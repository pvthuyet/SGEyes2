#include "watcher_manager.hpp"
#include "logger/logger_define.hpp"
#include "configuration/config_manager.hpp"
#include "services/service_manager.hpp"

SAIGON_NAMESPACE_BEGIN

watcher_manager::watcher_manager() = default;
watcher_manager::~watcher_manager() noexcept = default;

void watcher_manager::start()
{
	LOGENTER;
	config_ = std::make_unique<config_manager>();
	config_->load("config.json");

	services_ = std::make_unique<service_manager>();
	services_->start_listening(config_->get_port());

	LOGEXIT;
}

SAIGON_NAMESPACE_END