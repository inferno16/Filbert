#pragma once
#include "Event.h"

namespace Filbert
{
	class FLB_API AppEvent : public Event 
	{
	public:
		EVENT_CLASS_CATEGORY(EC_Application)
	};

	class FLB_API AppTickEvent : public AppEvent
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
	};

	class FLB_API AppUpdateEvent : public AppEvent
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class FLB_API AppRenderEvent : public AppEvent
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
	};
}