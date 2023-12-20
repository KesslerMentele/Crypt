#pragma once

#include "Crypt/Core/Core.h"
#include "Crypt/Core/KeyCodes.h"
#include "Crypt/Core/MouseCodes.h"


namespace Crypt {
	class Input
	{
	public: 

		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}