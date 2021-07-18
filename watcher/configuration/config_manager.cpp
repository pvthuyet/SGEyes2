#include "config_manager.hpp"
#include <nlohmann/json.hpp>
#include <logger/logger_define.hpp>
#include <fstream>

SAIGON_NAMESPACE_BEGIN
short config_manager::get_port() const noexcept
{
	return port_;
}

void config_manager::load(std::string_view path)
{
	using json = nlohmann::json;
	std::ifstream ifs(path.data());
	auto config = json::parse(ifs);
	port_ = config["port"].get<short>();
	SPDLOG_INFO("port: {}", port_);
}
SAIGON_NAMESPACE_END
