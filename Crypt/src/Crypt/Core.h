#pragma once

#ifdef CRY_PLATFORM_WINDOWS
#if CRY_DYNAMIC_LINK
	#ifdef CRY_BUILD_DLL
		#define CRYPT_API __declspec(dllexport)
	#else 
		#define CRYPT_API __declspec(dllimport)
	#endif
#else 
	#define CRYPT_API
#endif
#else
	#error Crypt only supports Windows!
#endif

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