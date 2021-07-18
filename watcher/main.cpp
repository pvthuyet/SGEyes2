#include <iostream>
#include <vld.h>
#include "logger/logger.hpp"
#include "logger/logger_define.hpp"
#include "configuration/config_manager.hpp"
#include "watcher_manager.hpp"

int main()
{
	try {
		sg::logger::get_instance();
		sg::config_manager config;
		config.load("config.json");

		sg::watcher_manager watcher{};
		watcher.start();

	}
	catch (std::exception& ex) {
		SPDLOG_ERROR(ex.what());
	}

	return EXIT_SUCCESS;
}