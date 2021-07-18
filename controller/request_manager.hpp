#pragma once
#include "../watcher/define.hpp"
#include "server.hpp"
#include <string>

SAIGON_NAMESPACE_BEGIN
class request_manager
{
private:
	server server_;

public:
	request_manager(std::string_view endpoint);
	void send(std::string const& msg);
};

SAIGON_NAMESPACE_END