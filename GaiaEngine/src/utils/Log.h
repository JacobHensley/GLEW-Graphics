#pragma once
#include "GaPCH.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Common.h"

class Log
{
public:
	static void Init();

	inline static void SetCoreLevel(spdlog::level::level_enum level) { s_CoreLogger->set_level(level); };
	inline static void SetClientLevel(spdlog::level::level_enum level) { s_ClientLogger->set_level(level); };

	inline static void SetCorePattern(const String& pattern) { s_CoreLogger->set_pattern(pattern); }
	inline static void SetClientPattern(const String& pattern) { s_ClientLogger->set_pattern(pattern); }

	inline static void DisablePattern() { s_CoreLogger->set_pattern("%v"); }
	inline static void EnablePattern() { s_CoreLogger->set_pattern("%^[%T] [%l] %n: %v%$"); }

	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

//For temporary logging
#define GA_LOG(...)           Log::GetCoreLogger()->trace(__VA_ARGS__)

// Core log macros
#define GA_CORE_TRACE(...)    Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GA_CORE_DEBUG(...)    Log::GetCoreLogger()->debug(__VA_ARGS__)
#define GA_CORE_INFO(...)     Log::GetCoreLogger()->info(__VA_ARGS__)
#define GA_CORE_WARN(...)     Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GA_CORE_ERROR(...)    Log::GetCoreLogger()->error(__VA_ARGS__)
#define GA_CORE_CRITICAL(...) Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define GA_TRACE(...)	       Log::GetClientLogger()->trace(__VA_ARGS__)
#define GA_DEBUG(...)         Log::GetClientLogger()->debug(__VA_ARGS__)
#define GA_INFO(...)	       Log::GetClientLogger()->info(__VA_ARGS__)
#define GA_WARN(...)	       Log::GetClientLogger()->warn(__VA_ARGS__)
#define GA_ERROR(...)	       Log::GetClientLogger()->error(__VA_ARGS__)
#define GA_CRITICAL(...)      Log::GetClientLogger()->critical(__VA_ARGS__)

//Level macros
#define GA_LEVEL_TRACE        spdlog::level::trace
#define GA_LEVEL_DEBUG        spdlog::level::debug
#define GA_LEVEL_INFO         spdlog::level::info
#define GA_LEVEL_WARN         spdlog::level::warn
#define GA_LEVEL_ERROR        spdlog::level::err
#define GA_LEVEL_CRITICAL     spdlog::level::critical