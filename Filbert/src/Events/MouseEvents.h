#pragma once
#include "Event.h"

namespace Filbert
{
	class FLB_API MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EC_Input | EC_Mouse)
	};

	class FLB_API MouseButtonEvent : public MouseEvent
	{
	protected:
		MouseButtonEvent(cui32& button) : m_Button(button) {}
		ui32 m_Button;
	};
	
	class FLB_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(cui32& button) : MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class FLB_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(cui32& button) : MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class FLB_API MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(const double& x, const double& y) : m_X(x), m_Y(y) {}
		EVENT_CLASS_TYPE(MouseMoved)
	private:
		double m_X;
		double m_Y;
	};

	class FLB_API MouseScrolledEvent : public MouseEvent
	{
	public:
		MouseScrolledEvent(cui32& xOffset, cui32& yOffset) : m_XOffset(xOffset), m_YOffset(xOffset) {}
		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		ui32 m_XOffset;
		ui32 m_YOffset;
	};
}