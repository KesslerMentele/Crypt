#pragma once

#ifdef CRY_PLATFORM_WINDOWS
	#ifdef CRY_BUILD_DLL
		#define CRYPT_API __declspec(dllexport)
	#else 
		#define CRYPT_API __declspec(dllimport)
	#endif
#else
	#error Crypt only supports Windows!
#endif

#define BIT(x) (1 << x)