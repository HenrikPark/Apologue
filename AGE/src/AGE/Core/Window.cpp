#include "AGEpch.h"
#include "AGE/Core/Window.h"
#include "Platform/Windows/WindowsWindow.h"


namespace AGE
{
	Scope<AGE::Window> Window::Create(const AGE::WindowProps& props)
	{
#ifdef AGE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		AGE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}