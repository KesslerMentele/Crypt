#pragma once

namespace Crypt {

/* Printable keys from glfw3.h*/
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

#define CRY_KEY_SPACE           ::Crypt::Key::Space
#define CRY_KEY_APOSTROPHE      ::Crypt::Key::Apostrophe    /* ' */
#define CRY_KEY_COMMA           ::Crypt::Key::Comma         /* , */
#define CRY_KEY_MINUS           ::Crypt::Key::Minus         /* - */
#define CRY_KEY_PERIOD          ::Crypt::Key::Period        /* . */
#define CRY_KEY_SLASH           ::Crypt::Key::Slash         /* / */
#define CRY_KEY_0               ::Crypt::Key::D0
#define CRY_KEY_1               ::Crypt::Key::D1
#define CRY_KEY_2               ::Crypt::Key::D2
#define CRY_KEY_3               ::Crypt::Key::D3
#define CRY_KEY_4               ::Crypt::Key::D4
#define CRY_KEY_5               ::Crypt::Key::D5
#define CRY_KEY_6               ::Crypt::Key::D6
#define CRY_KEY_7               ::Crypt::Key::D7
#define CRY_KEY_8               ::Crypt::Key::D8
#define CRY_KEY_9               ::Crypt::Key::D9
#define CRY_KEY_SEMICOLON       ::Crypt::Key::Semicolon     /* ; */
#define CRY_KEY_EQUAL           ::Crypt::Key::Equal         /* = */
#define CRY_KEY_A               ::Crypt::Key::A
#define CRY_KEY_B               ::Crypt::Key::B
#define CRY_KEY_C               ::Crypt::Key::C
#define CRY_KEY_D               ::Crypt::Key::D
#define CRY_KEY_E               ::Crypt::Key::E
#define CRY_KEY_F               ::Crypt::Key::F
#define CRY_KEY_G               ::Crypt::Key::G
#define CRY_KEY_H               ::Crypt::Key::H
#define CRY_KEY_I               ::Crypt::Key::I
#define CRY_KEY_J               ::Crypt::Key::J
#define CRY_KEY_K               ::Crypt::Key::K
#define CRY_KEY_L               ::Crypt::Key::L
#define CRY_KEY_M               ::Crypt::Key::M
#define CRY_KEY_N               ::Crypt::Key::N
#define CRY_KEY_O               ::Crypt::Key::O
#define CRY_KEY_P               ::Crypt::Key::P
#define CRY_KEY_Q               ::Crypt::Key::Q
#define CRY_KEY_R               ::Crypt::Key::R
#define CRY_KEY_S               ::Crypt::Key::S
#define CRY_KEY_T               ::Crypt::Key::T
#define CRY_KEY_U               ::Crypt::Key::U
#define CRY_KEY_V               ::Crypt::Key::V
#define CRY_KEY_W               ::Crypt::Key::W
#define CRY_KEY_X               ::Crypt::Key::X
#define CRY_KEY_Y               ::Crypt::Key::Y
#define CRY_KEY_Z               ::Crypt::Key::Z
#define CRY_KEY_LEFT_BRACKET    ::Crypt::Key::LeftBracket   /* [ */
#define CRY_KEY_BACKSLASH       ::Crypt::Key::Backslash     /* \ */
#define CRY_KEY_RIGHT_BRACKET   ::Crypt::Key::RightBracket  /* ] */
#define CRY_KEY_GRAVE_ACCENT    ::Crypt::Key::GraveAccent   /* ` */
#define CRY_KEY_WORLD_1         ::Crypt::Key::World1        /* non-US #1 */
#define CRY_KEY_WORLD_2         ::Crypt::Key::World2        /* non-US #2 */

/* Function keys */
#define CRY_KEY_ESCAPE          ::Crypt::Key::Escape
#define CRY_KEY_ENTER           ::Crypt::Key::Enter
#define CRY_KEY_TAB             ::Crypt::Key::Tab
#define CRY_KEY_BACKSPACE       ::Crypt::Key::Backspace
#define CRY_KEY_INSERT          ::Crypt::Key::Insert
#define CRY_KEY_DELETE          ::Crypt::Key::Delete
#define CRY_KEY_RIGHT           ::Crypt::Key::Right
#define CRY_KEY_LEFT            ::Crypt::Key::Left
#define CRY_KEY_DOWN            ::Crypt::Key::Down
#define CRY_KEY_UP              ::Crypt::Key::Up
#define CRY_KEY_PAGE_UP         ::Crypt::Key::PageUp
#define CRY_KEY_PAGE_DOWN       ::Crypt::Key::PageDown
#define CRY_KEY_HOME            ::Crypt::Key::Home
#define CRY_KEY_END             ::Crypt::Key::End
#define CRY_KEY_CAPS_LOCK       ::Crypt::Key::CapsLock
#define CRY_KEY_SCROLL_LOCK     ::Crypt::Key::ScrollLock
#define CRY_KEY_NUM_LOCK        ::Crypt::Key::NumLock
#define CRY_KEY_PRINT_SCREEN    ::Crypt::Key::PrintScreen
#define CRY_KEY_PAUSE           ::Crypt::Key::Pause
#define CRY_KEY_F1              ::Crypt::Key::F1
#define CRY_KEY_F2              ::Crypt::Key::F2
#define CRY_KEY_F3              ::Crypt::Key::F3
#define CRY_KEY_F4              ::Crypt::Key::F4
#define CRY_KEY_F5              ::Crypt::Key::F5
#define CRY_KEY_F6              ::Crypt::Key::F6
#define CRY_KEY_F7              ::Crypt::Key::F7
#define CRY_KEY_F8              ::Crypt::Key::F8
#define CRY_KEY_F9              ::Crypt::Key::F9
#define CRY_KEY_F10             ::Crypt::Key::F10
#define CRY_KEY_F11             ::Crypt::Key::F11
#define CRY_KEY_F12             ::Crypt::Key::F12
#define CRY_KEY_F13             ::Crypt::Key::F13
#define CRY_KEY_F14             ::Crypt::Key::F14
#define CRY_KEY_F15             ::Crypt::Key::F15
#define CRY_KEY_F16             ::Crypt::Key::F16
#define CRY_KEY_F17             ::Crypt::Key::F17
#define CRY_KEY_F18             ::Crypt::Key::F18
#define CRY_KEY_F19             ::Crypt::Key::F19
#define CRY_KEY_F20             ::Crypt::Key::F20
#define CRY_KEY_F21             ::Crypt::Key::F21
#define CRY_KEY_F22             ::Crypt::Key::F22
#define CRY_KEY_F23             ::Crypt::Key::F23
#define CRY_KEY_F24             ::Crypt::Key::F24
#define CRY_KEY_F25             ::Crypt::Key::F25

/* Keypad */
#define CRY_KEY_KP_0            ::Crypt::Key::KP0
#define CRY_KEY_KP_1            ::Crypt::Key::KP1
#define CRY_KEY_KP_2            ::Crypt::Key::KP2
#define CRY_KEY_KP_3            ::Crypt::Key::KP3
#define CRY_KEY_KP_4            ::Crypt::Key::KP4
#define CRY_KEY_KP_5            ::Crypt::Key::KP5
#define CRY_KEY_KP_6            ::Crypt::Key::KP6
#define CRY_KEY_KP_7            ::Crypt::Key::KP7
#define CRY_KEY_KP_8            ::Crypt::Key::KP8
#define CRY_KEY_KP_9            ::Crypt::Key::KP9
#define CRY_KEY_KP_DECIMAL      ::Crypt::Key::KPDecimal
#define CRY_KEY_KP_DIVIDE       ::Crypt::Key::KPDivide
#define CRY_KEY_KP_MULTIPLY     ::Crypt::Key::KPMultiply
#define CRY_KEY_KP_SUBTRACT     ::Crypt::Key::KPSubtract
#define CRY_KEY_KP_ADD          ::Crypt::Key::KPAdd
#define CRY_KEY_KP_ENTER        ::Crypt::Key::KPEnter
#define CRY_KEY_KP_EQUAL        ::Crypt::Key::KPEqual

#define CRY_KEY_LEFT_SHIFT      ::Crypt::Key::LeftShift
#define CRY_KEY_LEFT_CONTROL    ::Crypt::Key::LeftControl
#define CRY_KEY_LEFT_ALT        ::Crypt::Key::LeftAlt
#define CRY_KEY_LEFT_SUPER      ::Crypt::Key::LeftSuper
#define CRY_KEY_RIGHT_SHIFT     ::Crypt::Key::RightShift
#define CRY_KEY_RIGHT_CONTROL   ::Crypt::Key::RightControl
#define CRY_KEY_RIGHT_ALT       ::Crypt::Key::RightAlt
#define CRY_KEY_RIGHT_SUPER     ::Crypt::Key::RightSuper
#define CRY_KEY_MENU            ::Crypt::Key::Menu