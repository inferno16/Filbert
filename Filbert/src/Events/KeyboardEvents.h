#pragma once
#include "Event.h"

namespace Filbert
{
	class FLB_API KeyEvent : public Event
	{
	protected:
		KeyEvent(cui32& code) : m_KeyCode(code) {}
	public:
		inline ui32 GetKeyCode() { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EC_Input | EC_Keyboard)

	protected:
		ui32 m_KeyCode;
	};

	class FLB_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(cui32& code, const bool& repeated) : KeyEvent(code), m_Repeated(repeated) {}
		inline bool IsRepeated() { return m_Repeated; }
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_Repeated;
	};

	class FLB_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(cui32& code) : KeyEvent(code) {}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}