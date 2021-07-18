#include "server.hpp"
#include <fmt/core.h>

SAIGON_NAMESPACE_BEGIN
server::server(std::string_view ep) :
	ctx_{},
	sock_(ctx_, zmqpp::socket_type::router),
	endpoint_(ep)
{
	sock_.set(zmqpp::socket_option::identity, "client 1");
	sock_.connect(endpoint_);
	fmt::print("Connect to {}\n", endpoint_);
}

void server::send(std::string const& req)
{
	zmqpp::message_t msg;
	msg << endpoint_;
	msg << req;
	sock_.send(msg);
}

SAIGON_NAMESPACE_END