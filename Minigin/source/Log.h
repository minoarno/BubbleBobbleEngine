#pragma once
//Mentioned in the youtube video of The Cherno about Logging
//https://www.youtube.com/watch?v=dZr-53LAlOw&t=915s
//Installed from the github page
//https://github.com/gabime/spdlog

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace MidestinyEngine
{
	class Log
	{
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define ME_CORE_TRACE(...) ::MidestinyEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ME_CORE_INFO(...)  ::MidestinyEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ME_CORE_WARN(...)  ::MidestinyEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ME_CORE_ERROR(...) ::MidestinyEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ME_CORE_FATAL(...) ::MidestinyEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define ME_TRACE(...)      ::MidestinyEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ME_INFO(...)       ::MidestinyEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ME_WARN(...)       ::MidestinyEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ME_ERROR(...)      ::MidestinyEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ME_FATAL(...)      ::MidestinyEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)