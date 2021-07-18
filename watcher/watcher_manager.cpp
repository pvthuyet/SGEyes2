#include "watcher_manager.hpp"
#include "logger/logger_define.hpp"

SAIGON_NAMESPACE_BEGIN

void watcher_manager::start()
{
	LOGENTER;
	SPDLOG_DEBUG("debug mode on");
	throw std::runtime_error("test throw");
	LOGEXIT;
}

SAIGON_NAMESPACE_END