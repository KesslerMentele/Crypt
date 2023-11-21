#pragma once

#include <memory>



//#ifdef CRY_PLATFORM_WINDOWS
//#if CRY_DYNAMIC_LINK
//	#ifdef CRY_BUILD_DLL
//		#define CRYPT_API __declspec(dllexport)

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

//// DLL support
//#ifdef CRY_PLATFORM_WINDOWS
//	#if CRY_DYNAMIC_LINK
//		#ifdef HZ_BUILD_DLL
//			#define CRYPT_API __declspec(dllexport)
//		#else
//			#define CRYPT_API __declspec(dllimport)
//		#endif
//	#else
//		#define CRYPT_API
//	#endif
//#else
//	#error "Crypt only supports Windows!"
//#endif // End of DLL support

#ifdef CRY_DEBUG
	#define CRY_ENABLE_ASSERTS
#endif

#ifdef CRY_ENABLE_ASSERTS
	#define CRY_ASSERT(x,...) {if(!(x)) { CRY_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CRY_CORE_ASSERT(x,...) {if(!(x)) { CRY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else 
	#define CRY_ASSERT(x,...) 
	#define CRY_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1 << x)

#define CRY_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)


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