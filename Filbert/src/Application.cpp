#include "filbertPCH.h"
#include "Application.h"
#include "Input.h"

namespace Filbert {
	Application* Application::s_Instance;

	Application::Application()
	{
		FLB_ASSERT(!s_Instance, "Error creating second instance of Application. Application is a singleton!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {}

	void Application::Run()
	{
		while (m_Running) {
			m_Window->Update();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher d(e);
		d.Dispatch<WindowClosedEvent>([this](WindowClosedEvent& e) { m_Running = false; return true; });
	}
}
