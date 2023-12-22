#pragma once
#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include <memory>


#ifdef _WIN32
	#ifdef _WIN64
		#define CRY_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define CRY_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define CRY_PLATFORM_MACOS
		#error "MacOS is not supported!" 
	#else
		#error "Unknown apple platform!"
	#endif
#elif defined(__ANDROID__)
	#define CRY_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define CRY_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	#error "Unknown platform!"
#endif


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


#ifdef CRY_ENABLE_ASSERTS
	#define CRY_ASSERT(x,...) {if(!(x)) { CRY_ERROR("Assertion Failed: {0}", __VA_ARGS__); CRY_DEBUGBREAK(); } }
	#define CRY_CORE_ASSERT(x,...) {if(!(x)) { CRY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);  CRY_DEBUGBREAK(); } }
#else 
	#define CRY_ASSERT(x,...) 
	#define CRY_CORE_ASSERT(x,...)
#endif

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