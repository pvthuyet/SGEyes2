#pragma once

#include "define.hpp"
#include <thread>
#include <memory>

SAIGON_NAMESPACE_BEGIN
class config_manager;
class service_manager;

/// <summary>
/// manage watcher all from project
/// </summary>
class watcher_manager
{
private:
	std::unique_ptr<config_manager> config_;
	std::unique_ptr<service_manager> services_;

public:
	watcher_manager();
	~watcher_manager() noexcept;

	/// <summary>
	/// start watcher
	/// </summary>
	void start();
};

SAIGON_NAMESPACE_END