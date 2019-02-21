#pragma once
#include "filbertPCH.h"
#include "Core.h"

namespace Filbert 
{
	enum class EventType {
		None = 0,
		AppTick, AppUpdate, AppRender,
		WindowClosed, WindowResized, WindowFocusChanged, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		JoystickButtonPressed, JoystickButtonReleased, JoystickAxis
	};

	enum EventCategory : ui32 {
		EC_None        = 0,
		EC_Application = 0x1,
		EC_Window      = 0x2,
		EC_Input       = 0x4,
		EC_Keyboard    = 0x8,
		EC_Mouse       = 0x10,
		EC_Joystick    = 0x20,
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual ui32 GetCategoryFlags() const override { return category; }

	class FLB_API Event
	{
		friend class EventDispatcher;
	public:
		virtual ~Event() {}
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual ui32 GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		friend inline std::ostream& operator<<(std::ostream& out, const Event& e) {
			return out << e.ToString();
		}

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
}
