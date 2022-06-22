#pragma once

#include "Core.h"

namespace AGE
{
	class AGE_API Application
	{
	public:
		Application();
		virtual ~Application();	

		void Run();
	};

	//To be Defined in client
	Application* CreateApplication();

}

