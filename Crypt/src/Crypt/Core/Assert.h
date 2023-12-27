#pragma once

#include "Crypt/Core/Core.h"
#include "Crypt/Core/Log.h"

#ifdef CRY_ENABLE_ASSERTS
namespace Crypt::Assert
{
	constexpr const char* CurrentFileName(const char* path) {
		const char* file = path;
		while (*path)
		{
			if (*path == '/' || *path == '\\')
				file = ++path;
			else
				path++;
		}
		return file;
	}
}

#define CRY_INTERNAL_ASSERT_IMPL(type, check, msg, ...) {if (!(check)) { CRY##type##ERROR(msg, __VA_ARGS__); CRY_DEBUGBREAK(); } }
#define CRY_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CRY_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: '{0}'", __VA_ARGS__)
#define CRY_INTERNAL_ASSERT_NO_MSG(type, check) CRY_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", CRY_STRINGIFY_MACRO(check), ::Crypt::Assert::CurrentFileName(__FILE__), __LINE__)

#define CRY_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define CRY_INTERNAL_ASSERT_GET_MACRO(...) CRY_EXPAND_MACRO( CRY_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CRY_INTERNAL_ASSERT_WITH_MSG, CRY_INTERNAL_ASSERT_NO_MSG) )

#define CRY_ASSERT(...) CRY_EXPAND_MACRO( CRY_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define CRY_CORE_ASSERT(...) CRY_EXPAND_MACRO( CRY_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define CRY_ASSERT(...)
#define CRY_CORE_ASSERT(...)

#endif
