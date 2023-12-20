#pragma once

namespace Crypt
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define CRY_MOUSE_BUTTON_0      ::Crypt::Mouse::Button0
#define CRY_MOUSE_BUTTON_1      ::Crypt::Mouse::Button1
#define CRY_MOUSE_BUTTON_2      ::Crypt::Mouse::Button2
#define CRY_MOUSE_BUTTON_3      ::Crypt::Mouse::Button3
#define CRY_MOUSE_BUTTON_4      ::Crypt::Mouse::Button4
#define CRY_MOUSE_BUTTON_5      ::Crypt::Mouse::Button5
#define CRY_MOUSE_BUTTON_6      ::Crypt::Mouse::Button6
#define CRY_MOUSE_BUTTON_7      ::Crypt::Mouse::Button7
#define CRY_MOUSE_BUTTON_LAST   ::Crypt::Mouse::ButtonLast
#define CRY_MOUSE_BUTTON_LEFT   ::Crypt::Mouse::ButtonLeft
#define CRY_MOUSE_BUTTON_RIGHT  ::Crypt::Mouse::ButtonRight
#define CRY_MOUSE_BUTTON_MIDDLE ::Crypt::Mouse::ButtonMiddle