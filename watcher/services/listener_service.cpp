#include "listener_service.hpp"
#include "logger/logger_define.hpp"
#include <format>
#include <zmqpp/zmqpp.hpp>
#include <thread>

SAIGON_NAMESPACE_BEGIN

void listener_service::start(short port)
{
	LOGENTER;
	using namespace std::string_literals;
	std::jthread t([port](std::stop_token tok) {
		zmqpp::context ctx;
		zmqpp::socket sock(ctx, zmqpp::socket_type::router);

		auto id = std::format("tcp://localhost:{}", port);
		auto ep = std::format("tcp://*:{}", port);
		SPDLOG_INFO("Start listening service at {}. Service id {}", ep, id);

		sock.set(zmqpp::socket_option::identity, id);
		sock.bind(ep);

		zmqpp::poller poller{};
		poller.add(sock);

		while (!tok.stop_requested()) {
			poller.poll(1000);
			if (poller.events(sock) == zmqpp::poller_t::poll_in) {
				zmqpp::message_t msg;
				sock.receive(msg);

				// Frame 0: identity of client
				// Frame 1: PING or client control frame
				// Frame 2: request body
				std::string ident, control, body;
				msg >> ident;
				msg >> control;
				SPDLOG_DEBUG("{} {}", ident, control);
				if (control == "STOP"s) {
					break;
				}
				else {

				}
			}
		}
		});

	t.join();
	LOGEXIT;
}

SAIGON_NAMESPACE_END