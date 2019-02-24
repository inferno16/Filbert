#pragma once
#include "Event.h"
#include "Input.h"

namespace Filbert
{
	typedef Vector2<double> MousePosition;
	typedef Vector2<ui32> MouseScroll;

	class FLB_API MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EC_Input | EC_Mouse)
	};

	class FLB_API MouseButtonEvent : public MouseEvent
	{
	public:
		inline MouseCode GetButton() const { return m_Button; }
	protected:
		MouseButtonEvent(const MouseCode& button) : m_Button(button) {}
		MouseCode m_Button;
	};
	
	class FLB_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseCode& button) : MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class FLB_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseCode& button) : MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class FLB_API MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(const double& x, const double& y) : m_Position(x, y) {}
		MouseMovedEvent(const MousePosition& pos) : m_Position(pos) {}

		inline MousePosition GetPosition() const { return m_Position; }
		EVENT_CLASS_TYPE(MouseMoved)
	private:
		MousePosition m_Position;
	};

	class FLB_API MouseScrolledEvent : public MouseEvent
	{
	public:
		MouseScrolledEvent(cui32& xOffset, cui32& yOffset) : m_Offset(xOffset, xOffset) {}
		MouseScrolledEvent(const MouseScroll& offset) : m_Offset(offset) {}

		MouseScroll GetOffset() { return m_Offset; }
		inline EVENT_CLASS_TYPE(MouseScrolled);
	private:
		MouseScroll m_Offset;
	};
}