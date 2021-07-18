#pragma once
#include "define.hpp"
#include "listener_service.hpp"

SAIGON_NAMESPACE_BEGIN
class service_manager
{
private:
	listener_service listener_;

public:
	void start_listening(short port);
};

SAIGON_NAMESPACE_END