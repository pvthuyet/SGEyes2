#pragma once

#include "../watcher/define.hpp"
#include <string>
#include <zmqpp/zmqpp.hpp>

SAIGON_NAMESPACE_BEGIN
class server
{
private:
	zmqpp::context_t ctx_;
	zmqpp::socket_t sock_;

	// server identity/endpoint
	std::string endpoint_;

public:
	server(std::string_view ep);
	void send(std::string const& req);
};

SAIGON_NAMESPACE_END