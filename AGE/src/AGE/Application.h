#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace AGE
{
	class AGE_API Application
	{
	public:
		Application();
		virtual ~Application();	

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be Defined in client
	Application* CreateApplication();

}

