#include <iostream>
#include <vld.h>
#include "logger/logger.hpp"
#include "logger/logger_define.hpp"
#include "watcher_manager.hpp"

int main()
{
	try {
		sg::logger::get_instance();
		sg::watcher_manager watcher{};
		watcher.start();
	}
	catch (std::exception& ex) {
		SPDLOG_ERROR(ex.what());
	}

	return EXIT_SUCCESS;
}