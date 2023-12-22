#pragma once

#include <glm/glm.hpp>
#include "Crypt/Core/KeyCodes.h"
#include "Crypt/Core/MouseCodes.h"


namespace Crypt {
	class Input
	{
	public: 

		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}