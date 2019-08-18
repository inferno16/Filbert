#pragma once
#include "Event.h"

namespace Filbert
{
	class JoystickEvent : public Event
	{
	protected:
		JoystickEvent(cui32& code) : m_ControlCode(code) {}
	public:
		EVENT_CLASS_CATEGORY(EC_Input | EC_Joystick)
	protected:
		ui32 m_ControlCode;
	};

	class JoystickButtonPressedEvent : public JoystickEvent
	{
	public:
		JoystickButtonPressedEvent(cui32& code, cui32& count) : JoystickEvent(code), m_Repeated(count) {}
		inline ui32 GetRepeat() { return m_Repeated; }
		EVENT_CLASS_TYPE(JoystickButtonPressed)
	private:
		ui32 m_Repeated;
	};

	class JoystickButtonReleasedEvent : public JoystickEvent
	{
	public:
		JoystickButtonReleasedEvent(cui32& code) : JoystickEvent(code) {}
		EVENT_CLASS_TYPE(JoystickButtonReleased)
	};

	class JoystickAxisEvent : public JoystickEvent
	{
	public:
		JoystickAxisEvent(cui32& axis, ci32& value) : JoystickEvent(axis), m_AxisValue(value) {}
		EVENT_CLASS_TYPE(JoystickAxis)
	private:
		i32 m_AxisValue;
	};
}