#include "crypch.h"
#include "Crypt/Core/Window.h"

#ifdef CRY_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif // CRY_PLATFORM_WINDOWS

namespace Crypt {
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef CRY_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		CRY_CORE_ASSERT(false, "Unknown Platform!");
		return nullptr;
#endif
	}
}
