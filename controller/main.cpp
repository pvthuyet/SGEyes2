#include <fmt/core.h>
#include <format>
#include <iostream>
#include <string>
#include <vld.h>
#include "request_manager.hpp"

int main(int argc, char* argv[])
{
	using namespace std::string_literals;
	if (argc < 2) {
		fmt::print("Usage: controller [port]\n");
		return 0;
	}
	sg::request_manager req(std::format("tcp://localhost:{}", argv[1]));

	while (true) {
		std::string msg;
		fmt::print("Send request: ");
		std::cin >> msg;
		req.send(msg);
		if (msg == "STOP"s) {
			break;
		}
		fmt::print("\n");
	}

	return EXIT_SUCCESS;
}