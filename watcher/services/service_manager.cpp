#include "service_manager.hpp"
#include "logger/logger_define.hpp"

SAIGON_NAMESPACE_BEGIN

void service_manager::start_listening(short port)
{
	LOGENTER;
	listener_.start(port);
	LOGEXIT;
}

SAIGON_NAMESPACE_END