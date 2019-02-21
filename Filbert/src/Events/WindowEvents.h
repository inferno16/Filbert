#pragma once
#include "Event.h"

namespace Filbert
{
	class FLB_API WindowEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EC_Window)
	};

	class FLB_API WindowClosedEvent : public WindowEvent
	{
	public:
		WindowClosedEvent() {}
		EVENT_CLASS_TYPE(WindowClosed)
	};

	class FLB_API WindowResizedEvent : public WindowEvent
	{
	public:
		WindowResizedEvent(cui32& width, cui32& height) : m_Width(width), m_Height(height) {}
		EVENT_CLASS_TYPE(WindowResized)
	private:
		ui32 m_Width;
		ui32 m_Height;
	};

	class FLB_API WindowFocusChangedEvent : public WindowEvent
	{
	public:
		WindowFocusChangedEvent(const bool& gained) : m_Focused(gained) {}
		EVENT_CLASS_TYPE(WindowFocusChanged)
	private:
		bool m_Focused;
	};

	class FLB_API WindowMovedEvent : public WindowEvent
	{
	public:
		WindowMovedEvent(cui32& x, cui32& y) : m_X(x), m_Y(y) {}
		EVENT_CLASS_TYPE(WindowMoved)
	private:
		ui32 m_X;
		ui32 m_Y;
	};
}