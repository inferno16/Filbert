#include "filbertPCH.h"
#include "Input.h"

namespace Filbert
{
	std::unordered_set<i16> Input::s_KeyCodesSet = { 0x00, 0x08,
		   0x09, 0x0C, 0x0D, 0x10, 0x11, 0x12, 0x13, 0x14, 0x1B, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
		   0x26, 0x27, 0x28, 0x2C, 0x2D, 0x2E, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
		   0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
		   0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x60,
		   0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
		   0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E,
		   0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x90, 0x91, 0xA0, 0xA1, 0xA2, 0xA3,
		   0xA4, 0xA5, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE2
	};

	BiMap<i16, i16> Input::s_GLFWLUT = { { // Left map is native -> GLFW, right is GLFW -> native
		{ 0x08, 259 }, { 0x09, 258 }, { 0x0D, 257 }, { 0x13, 284 }, { 0x14, 280 }, { 0x1B, 256 }, { 0x21, 266 },
		{ 0x22, 267 }, { 0x23, 269 }, { 0x24, 268 }, { 0x25, 263 }, { 0x26, 265 }, { 0x27, 262 }, { 0x28, 264 },
		{ 0x2C, 283 }, { 0x2D, 260 }, { 0x2E, 261 }, { 0x5B, 343 }, { 0x5C, 347 }, { 0x6A, 332 }, { 0x6B, 334 },
		{ 0x6D, 333 }, { 0x6F, 331 }, { 0x90, 282 }, { 0x91, 281 }, { 0xA0, 340 }, { 0xA1, 344 }, { 0xA2, 341 },
		{ 0xA3, 345 }, { 0xA4, 342 }, { 0xA5, 346 }, { 0xBA,  59 }, { 0xBB,  61 }, { 0xC0,  96 }, { 0xDE,  39 }
	} };


	i16 Input::ToGLFWKey(const KeyCode & key)
	{
		if (key == KeyCode::Separator || key == KeyCode::Decimal) // GLFW has only one of these
			return 330;

		return TranslateGLFW (
			static_cast<i16>(key),
			static_cast<i16>(KeyCode::F1), 290,
			static_cast<i16>(KeyCode::Num0), 320,
			static_cast<i16>(KeyCode::Comma), 44,
			static_cast<i16>(KeyCode::LBracket), 91,
			s_GLFWLUT.GetLeft()
		);
	}

	KeyCode Input::FromGLFWKey(ci16& key) {
		if (key == 330)
			return KeyCode::Decimal;
		else if (key == 335) // ToDo: Add distinction between numpad and regular enter
			return KeyCode::Return;

		i16 out = TranslateGLFW (key,
			290, static_cast<i16>(KeyCode::F1),
			320, static_cast<i16>(KeyCode::Num0),
			44, static_cast<i16>(KeyCode::Comma),
			91, static_cast<i16>(KeyCode::LBracket),
			s_GLFWLUT.GetRight()
		);
		return out == -1 ? KeyCode::UNKNOWN : static_cast<KeyCode>(out);
	}
	i16 Input::TranslateGLFW(ci16& key, ci16& f1i, ci16& f1o, ci16& num0i, ci16& num0o, ci16& oem1i, ci16& oem1o, ci16& oem2i, ci16& oem2o, const std::unordered_map<i16, i16>& lut)
	{
		if (IsKeyInRange(key, 48, 57) || IsKeyInRange(key, 65, 90) || key == 32) // Numbers, letters or space
			return key;

		if (IsKeyInRange(key, f1i, f1i + 23)) // Function keys
			return key - (f1i - f1o);
		else if (IsKeyInRange(key, num0i, num0i + 9)) // Numpad numbers
			return key - (num0i - num0o);
		else if (IsKeyInRange(key, oem1i, oem1i + 3)) // Comma(,), minus(-), period(.), slash(/)
			return key - (oem1i - oem1o);
		else if (IsKeyInRange(key, oem2i, oem2i + 5) && key != oem2i + 3) // Brackets([]), backslash(\) and 2 vendor/region specific
			return key - (oem2i - oem2o);

		return lut.find(key) == lut.end() ? -1 : lut.at(key);
	}
}