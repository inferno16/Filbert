#pragma once
#include "Core.h"
#include "Window.h"

namespace Filbert
{
	class FLB_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Used in the EntryPoint and should be defined by the user
	Application* CreateApplication();
}
