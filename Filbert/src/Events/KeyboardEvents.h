#pragma once
#include "Event.h"
#include "Input.h"

namespace Filbert
{
	class FLB_API KeyEvent : public Event
	{
	protected:
		KeyEvent(const KeyCode& code) : m_KeyCode(code) {}
	public:
		inline KeyCode GetKeyCode() { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EC_Input | EC_Keyboard)

	protected:
		KeyCode m_KeyCode;
	};

	class FLB_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode& code, const bool& repeated) : KeyEvent(code), m_Repeated(repeated) {}
		inline bool IsRepeated() { return m_Repeated; }
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_Repeated;
	};

	class FLB_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode& code) : KeyEvent(code) {}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}