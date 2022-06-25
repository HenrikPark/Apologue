#include "AGEpch.h"
#include "Application.h"

#include "AGE/Events/ApplicationEvent.h"
#include "AGE/Log.h"

namespace AGE
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		AGE_TRACE(e);
		while (true)
		{

		}
	}
}
