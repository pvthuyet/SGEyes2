#include "config_manager.hpp"
#include <nlohmann/json.hpp>
#include <logger/logger_define.hpp>
#include <fstream>

SAIGON_NAMESPACE_BEGIN
void config_manager::load(std::string_view path)
{
	using json = nlohmann::json;
	std::ifstream ifs(path.data());
	auto config = json::parse(ifs);
	auto port = config["port"].get<short>();
	SPDLOG_INFO("port: {}", port);
}
SAIGON_NAMESPACE_END
