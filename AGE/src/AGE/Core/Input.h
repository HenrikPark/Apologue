#pragma once

#include "AGE/Core/Base.h"

#include "AGE/Core/KeyCodes.h"
#include "AGE/Core/MouseButtonCodes.h"

namespace AGE
{
	class Input
	{	
	public:
		static bool IsKeyPressed(int keycode);

		static bool IsMouseButtonPressed(int button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();	
	};
}