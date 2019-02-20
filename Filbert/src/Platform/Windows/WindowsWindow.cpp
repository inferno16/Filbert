#include "filbertPCH.h"
#include "WindowsWindow.h"

namespace Filbert
{
	Window* Window::Create() { return new WindowsWindow(); }
	bool WindowsWindow::s_GLFWInitialized = false;

	WindowsWindow::WindowsWindow() { Init(); }
	WindowsWindow::~WindowsWindow() { Destroy(); }

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::Init()
	{
		FLB_INFO("Creating window {0} ({1}, {2})", m_WindowProps.Title, m_WindowProps.Size.Width, m_WindowProps.Size.Height);
		if (!s_GLFWInitialized)
		{
			FLB_ASSERT(glfwInit(), "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(
			static_cast<int>(m_WindowProps.Size.Width),
			static_cast<int>(m_WindowProps.Size.Height),
			m_WindowProps.Title.c_str(), nullptr, nullptr
		);
		FLB_ASSERT(m_Window, "Failed to create window!");
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		SetVSync(m_WindowProps.VSync);
	}

	void WindowsWindow::Destroy()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(const bool& state)
	{
		if (state)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_WindowProps.VSync = state;
	}
}