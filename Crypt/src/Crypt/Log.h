#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Crypt {

	class CRYPT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core log macros
#define CRY_CORE_TRACE(...)  ::Crypt::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CRY_CORE_INFO(...)   ::Crypt::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CRY_CORE_WARN(...)   ::Crypt::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CRY_CORE_ERROR(...)  ::Crypt::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CRY_CORE_FATAL(...)  ::Crypt::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client lgo macros
#define CRY_TRACE(...)  ::Crypt::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CRY_INFO(...)   ::Crypt::Log::GetClientLogger()->info(__VA_ARGS__)
#define CRY_WARN(...)   ::Crypt::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CRY_ERROR(...)  ::Crypt::Log::GetClientLogger()->error(__VA_ARGS__)
#define CRY_FATAL(...)  ::Crypt::Log::GetClientLogger()->fatal(__VA_ARGS__)