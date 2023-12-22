#pragma once

#include "Crypt/Core/PlatformDetection.h"

#ifdef CRY_PLATFORM_WINDOWS
#ifdef NOMINMAX
#define NOMINMAX
#endif
#endif // CRY_PLATFORM_WINDOWS



#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Crypt/Core/Core.h"

#include "Crypt/Core/Log.h"

#include "Crypt/Debug/Instrumentor.h"

#ifdef CRY_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

