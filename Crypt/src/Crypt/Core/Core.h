#pragma once
#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include <memory>
#include "Crypt/Core/PlatformDetection.h"

#ifdef CRY_DEBUG
	#if defined(CRY_PLATFORM_WINDOWS)
		#define CRY_DEBUGBREAK() __debugbreak()
	#elif defined(CRY_PLATFORM_LINUX)
		#include <signal.h>
		#define CRY_DEBUGBREAK() raise(SIGTRAP)
	#else 
		#error "Platform Doesn't support debugbreak yet!"
	#endif
	#define CRY_ENABLE_ASSERTS
#else
	#define CRY_DEBUGBREAK() 
#endif

#define CRY_EXPAND_MACRO(x) x
#define CRY_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define CRY_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...);}


namespace Crypt {


	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}


	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Crypt/Core/Log.h"
#include "Crypt/Core/Assert.h"
