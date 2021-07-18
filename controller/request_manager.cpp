#include "request_manager.hpp"

SAIGON_NAMESPACE_BEGIN
request_manager::request_manager(std::string_view endpoint):
	server_(endpoint)
{}

void request_manager::send(std::string const& msg)
{
	server_.send(msg);
}

SAIGON_NAMESPACE_END