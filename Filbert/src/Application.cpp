#include "filbertPCH.h"
#include "Application.h"

namespace Filbert {
	Application::Application()
	{
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
