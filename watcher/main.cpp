#include "watcher_manager.hpp"
#include "logger/logger.hpp"
#include <iostream>

int main()
{
	try {
		sg::logger::get_instance();
		sg::watcher_manager watcher{};
		watcher.start();
	}
	catch (std::exception& ex) {
		std::cerr << "[err] " << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}