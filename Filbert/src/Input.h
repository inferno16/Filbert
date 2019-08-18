#pragma once
#include "Types/Vector.h"
#include "Types/BiMap.h"

namespace Filbert
{
	/*
	enum class ScanCode
	{
		Escape     = 0x01,
		Key1       = 0x02,
		Key2       = 0x03,
		Key3       = 0x04,
		Key4       = 0x05,
		Key5       = 0x06,
		Key6       = 0x07,
		Key7       = 0x08,
		Key8       = 0x09,
		Key9       = 0x0A,
		Key0       = 0x0B,
		Minus      = 0x0C,
		Equals     = 0x0D,
		Back       = 0x0E,
		Tab        = 0x0F,
		Q          = 0x10,
		W          = 0x11,
		E          = 0x12,
		R          = 0x13,
		T          = 0x14,
		Y          = 0x15,
		U          = 0x16,
		I          = 0x17,
		O          = 0x18,
		P          = 0x19,
		LBracket   = 0x1A,
		RBracket   = 0x1B,
		Return     = 0x1C,
		LContol    = 0x1D,
		A          = 0x1E,
		S          = 0x1F,
		D          = 0x20,
		F          = 0x21,
		G          = 0x22,
		H          = 0x23,
		J          = 0x24,
		K          = 0x25,
		L          = 0x26,
		Semicolon  = 0x27,
		Apostrophe = 0x28,
		Grave      = 0x29,
		LShift     = 0x2A,
		Backslash  = 0x2B,
		Z          = 0x2C,
		X          = 0x2D,
		C          = 0x2E,
		V          = 0x2F,
		B          = 0x30,
		N          = 0x31,
		M          = 0x32,
		Comma      = 0x33,
		Period     = 0x34,
		Slash      = 0x35,
		RShift     = 0x36,
		Multiply   = 0x37,
		LMenu      = 0x38,
		Space      = 0x39,
		Capital    = 0x3A,
		F1         = 0x3B,
		F2         = 0x3C,
		F3         = 0x3D,
		F4         = 0x3E,
		F5         = 0x3F,
		F6         = 0x40,
		F7         = 0x41,
		F8         = 0x42,
		F9         = 0x43,
		F10        = 0x44,
		NumLock    = 0x45,
		Scroll     = 0x46,
		Num7       = 0x47,
		Num8       = 0x48,
		Num9       = 0x49,
		Subtract   = 0x4A,
		Num4       = 0x4B,
		Num5       = 0x4C,
		Num6       = 0x4D,
		Add        = 0x4E,
		Num1       = 0x4F,
		Num2       = 0x50,
		Num3       = 0x51,
		Num0       = 0x52,
		Decimal    = 0x53,
		F11        = 0x57,
		F12        = 0x58,
		F13        = 0x64,
		F14        = 0x65,
		F15        = 0x66,
		Kana       = 0x70,
		Convert    = 0x79,
		NoConvert  = 0x7B,
		YEN        = 0x7D,
		NumEquals  = 0x8D,
		Circumflex = 0x90,
		At         = 0x91,
		Colon      = 0x92,
		Underline  = 0x93,
		Kanji      = 0x94,
		Stop       = 0x95,
		AX         = 0x96,
		Unlabeled  = 0x97,
		NumEnter   = 0x9C,
		RControl   = 0x9D,
		NumComma   = 0xB3,
		Divide     = 0xB5,
		SysRq      = 0xB7,
		RMenu      = 0xB8,
		Pause      = 0xC5,
		Home       = 0xC7,
		Up         = 0xC8,
		Prior      = 0xC9,
		Left       = 0xCB,
		Right      = 0xCD,
		End        = 0xCF,
		Down       = 0xD0,
		Next       = 0xD1,
		Insert     = 0xD2,
		Delete     = 0xD3,
		LSuper     = 0xDB,
		RSuper     = 0xDC,
		Apps       = 0xDD,
		Power      = 0xDE,
		Sleep      = 0xDF
	};
	*/

	enum class KeyCode
	{
		UNKNOWN    = 0x00,
		Backspace  = 0x08, // BACKSPACE key
		Tab        = 0x09, // TAB key
		Clear      = 0x0C, // CLEAR key
		Return     = 0x0D, // ENTER key
		Shift      = 0x10, // SHIFT key
		Control    = 0x11, // CTRL key
		Alt        = 0x12, // ALT key
		Pause      = 0x13, // PAUSE key
		CapsLock   = 0x14, // CAPS LOCK key
		Escape     = 0x1B, // ESC key
		Space      = 0x20, // SPACEBAR
		PageUp     = 0x21, // PAGE UP key
		PageDown   = 0x22, // PAGE DOWN key
		End        = 0x23, // END key
		Home       = 0x24, // HOME key
		Left       = 0x25, // LEFT ARROW key
		Up         = 0x26, // UP ARROW key
		Right      = 0x27, // RIGHT ARROW key
		Down       = 0x28, // DOWN ARROW key
		PrintScr   = 0x2C, // PRINT SCREEN key
		Insert     = 0x2D, // INS key
		Delete     = 0x2E, // DEL key
		Key0       = 0x30, // 0 key
		Key1       = 0x31, // 1 key
		Key2       = 0x32, // 2 key
		Key3       = 0x33, // 3 key
		Key4       = 0x34, // 4 key
		Key5       = 0x35, // 5 key
		Key6       = 0x36, // 6 key
		Key7       = 0x37, // 7 key
		Key8       = 0x38, // 8 key
		Key9       = 0x39, // 9 key
		A          = 0x41, // A key
		B          = 0x42, // B key
		C          = 0x43, // C key
		D          = 0x44, // D key
		E          = 0x45, // E key
		F          = 0x46, // F key
		G          = 0x47, // G key
		H          = 0x48, // H key
		I          = 0x49, // I key
		J          = 0x4A, // J key
		K          = 0x4B, // K key
		L          = 0x4C, // L key
		M          = 0x4D, // M key
		N          = 0x4E, // N key
		O          = 0x4F, // O key
		P          = 0x50, // P key
		Q          = 0x51, // Q key
		R          = 0x52, // R key
		S          = 0x53, // S key
		T          = 0x54, // T key
		U          = 0x55, // U key
		V          = 0x56, // V key
		W          = 0x57, // W key
		X          = 0x58, // X key
		Y          = 0x59, // Y key
		Z          = 0x5A, // Z key
		LSuper     = 0x5B, // Left Windows/Command key
		RSuper     = 0x5C, // Right Windows/Command key
		Num0       = 0x60, // Numeric keypad 0 key
		Num1       = 0x61, // Numeric keypad 1 key
		Num2       = 0x62, // Numeric keypad 2 key
		Num3       = 0x63, // Numeric keypad 3 key
		Num4       = 0x64, // Numeric keypad 4 key
		Num5       = 0x65, // Numeric keypad 5 key
		Num6       = 0x66, // Numeric keypad 6 key
		Num7       = 0x67, // Numeric keypad 7 key
		Num8       = 0x68, // Numeric keypad 8 key
		Num9       = 0x69, // Numeric keypad 9 key
		Multiply   = 0x6A, // Multiply key
		Add        = 0x6B, // Add key
		Separator  = 0x6C, // Separator key
		Subtract   = 0x6D, // Subtract key
		Decimal    = 0x6E, // Decimal key
		Divide     = 0x6F, // Divide key
		F1         = 0x70, // F1 key
		F2         = 0x71, // F2 key
		F3         = 0x72, // F3 key
		F4         = 0x73, // F4 key
		F5         = 0x74, // F5 key
		F6         = 0x75, // F6 key
		F7         = 0x76, // F7 key
		F8         = 0x77, // F8 key
		F9         = 0x78, // F9 key
		F10        = 0x79, // F10 key
		F11        = 0x7A, // F11 key
		F12        = 0x7B, // F12 key
		F13        = 0x7C, // F13 key
		F14        = 0x7D, // F14 key
		F15        = 0x7E, // F15 key
		F16        = 0x7F, // F16 key
		F17        = 0x80, // F17 key
		F18        = 0x81, // F18 key
		F19        = 0x82, // F19 key
		F20        = 0x83, // F20 key
		F21        = 0x84, // F21 key
		F22        = 0x85, // F22 key
		F23        = 0x86, // F23 key
		F24        = 0x87, // F24 key
		NumLock    = 0x90, // NUM LOCK key
		ScrollLock = 0x91, // SCROLL LOCK key
		LShift     = 0xA0, // Left SHIFT key
		RShift     = 0xA1, // Right SHIFT key
		LControl   = 0xA2, // Left CONTROL key
		RControl   = 0xA3, // Right CONTROL key
		LAlt       = 0xA4, // Left Alt key
		RAlt       = 0xA5, // Right Alt key
		Semicolon  = 0xBA, // For the US standard keyboard, the ';:' key
		Equal      = 0xBB, // For any country/region, the '=+' key
		Comma      = 0xBC, // For any country/region, the ',<' key
		Minus      = 0xBD, // For any country/region, the '-_' key
		Period     = 0xBE, // For any country/region, the '.>' key
		Slash      = 0xBF, // For the US standard keyboard, the '/?' key
		Backtick   = 0xC0, // For the US standard keyboard, the '`~' key
		LBracket   = 0xDB, // For the US standard keyboard, the '[{' key
		Backslash  = 0xDC, // For the US standard keyboard, the '\|' key
		RBracket   = 0xDD, // For the US standard keyboard, the ']}' key
		Quote      = 0xDE, // For the US standard keyboard, the 'single-quote/double-quote' key
		OEM        = 0xDF, // Used for miscellaneous characters. It can vary by keyboard.
		OEM_102    = 0xE2  // Either the '<>' key or the '\|' key on the RT 102-key keyboard
	};

	enum class MouseCode
	{
		UNKNOWN  = 0x00,
		LButton  = 0x01, // Left mouse button
		RButton  = 0x02, // Right mouse button
		MButton  = 0x04, // Middle mouse button
		X1Button = 0x05, // X1 mouse button
		X2Button = 0x06  // X2 mouse button
	};

	typedef int JoyCode; // Placeholder

	class Input
	{
	public:
		static inline bool IsKeyPressed(const KeyCode& key) { return s_Instance->_IsKeyPressed(key); }
		static inline bool IsMouseButtonPressed(const MouseCode& btn) { return s_Instance->_IsMouseButtonPressed(btn); }
		static inline bool IsJoystickButtonPressed(const JoyCode& btn) { return false; } // ToDo: Implement Joystick input
		static inline Vector2<double> GetMousePosition() { return s_Instance->_GetMousePosition(); };

		static inline i16 ToDXKey(const KeyCode& key) { return static_cast<int>(key); }
		static inline i16 ToDXMouse(const MouseCode& key) { return static_cast<int>(key); }
		static i16 ToGLFWKey(const KeyCode& key);
		static inline i16 ToGLFWMouse(const MouseCode& key) { i16 k = static_cast<int>(key); return k - ((k <= 2) ? 1 : 2); }

		static inline KeyCode FromDXKey(ci16& key, const bool& verify = true) {
			return (verify && !IsValidKeyCode(key)) ? KeyCode::UNKNOWN : static_cast<KeyCode>(key);
		}
		static inline MouseCode FromDXMouse(ci16& key, const bool& verify = true) {
			return (verify && !IsValidMouseCode(key)) ? MouseCode::UNKNOWN : static_cast<MouseCode>(key);
		}
		static KeyCode FromGLFWKey(ci16& key);
		static inline MouseCode FromGLFWMouse(ci16& key, const bool& verify = true) {
			i16 k = key + ((key < 2) ? 1 : 2);
			return (verify && !IsValidMouseCode(k)) ? MouseCode::UNKNOWN : static_cast<MouseCode>(k);
		}

	protected:
		virtual bool _IsKeyPressed(const KeyCode& key) const = 0;
		virtual bool _IsMouseButtonPressed(const MouseCode& btn) const = 0;
		virtual Vector2<double> _GetMousePosition() const = 0;

	private:
		static inline bool IsValidKeyCode(ci16& key) { return s_KeyCodesSet.find(key) != s_KeyCodesSet.end(); }
		static inline bool IsValidMouseCode(ci16& key) { return IsKeyInRange(key, 0, 6) && key != 3; }
		static inline bool IsKeyInRange(ci16& key, ci16& start, ci16& end) { return key >= start && key <= end; }
		// i = input(the key that is converted from), o = output (the key that is converted to)
		static i16 TranslateGLFW(ci16& key, ci16& f1i, ci16& f1o, ci16& num0i, ci16& num0o, ci16& oem1i,
			ci16& oem1o, ci16& oem2i, ci16& oem2o, const std::unordered_map<i16, i16>& lut);

	private:
		static Input* s_Instance;
		static std::unordered_set<i16> s_KeyCodesSet;
		static BiMap<i16, i16> s_GLFWLUT;
	};
}