#pragma once

#include "define.hpp"
#include <string>

SAIGON_NAMESPACE_BEGIN

class config_manager
{
private:
	short port_;

public:
	short get_port() const noexcept;

	void load(std::string_view path);
};

SAIGON_NAMESPACE_END