#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace AGE
{
	class AGE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	
}

//Core log macros
#define AGE_CORE_TRACE(...) ::AGE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AGE_CORE_INFO(...)  ::AGE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AGE_CORE_WARN(...)  ::AGE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AGE_CORE_ERROR(...) ::AGE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AGE_CORE_FATAL(...) ::AGE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define AGE_TRACE(...)      ::AGE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AGE_INFO(...)       ::AGE::Log::GetClientLogger()->info(__VA_ARGS__)
#define AGE_WARN(...)       ::AGE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AGE_ERROR(...)      ::AGE::Log::GetClientLogger()->error(__VA_ARGS__)
#define AGE_FATAL(...)      ::AGE::Log::GetClientLogger()->fatal(__VA_ARGS__)
