#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/WindowEvents.h"

namespace Filbert
{
	class FLB_API Application
	{
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& e);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		static Application* s_Instance;
	};

	// Used in the EntryPoint and should be defined by the user
	Application* CreateApplication();
}
