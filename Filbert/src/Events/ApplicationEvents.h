#pragma once
#include "Event.h"

namespace Filbert
{
	class AppEvent : public Event 
	{
	public:
		EVENT_CLASS_CATEGORY(EC_Application)
	};

	class AppTickEvent : public AppEvent
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
	};

	class AppUpdateEvent : public AppEvent
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class AppRenderEvent : public AppEvent
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
	};
}