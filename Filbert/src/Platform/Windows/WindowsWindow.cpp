#include "filbertPCH.h"
#include "WindowsWindow.h"
#include "Events/WindowEvents.h"
#include "Events/KeyboardEvents.h"
#include "Events/MouseEvents.h"
#include "Events/JoystickEvents.h"

namespace Filbert
{
	Window* Window::Create() { return new WindowsWindow(); }
	bool WindowsWindow::s_GLFWInitialized = false;

	WindowsWindow::WindowsWindow() { Init(); }
	WindowsWindow::~WindowsWindow() { Destroy(); }

	void WindowsWindow::Update()
	{
		glClear(GL_COLOR_BUFFER_BIT);
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
		int posX, posY;
		glfwGetWindowPos(m_Window, &posX, &posY);
		SetPosition(posX, posY);
		FLB_ASSERT(m_Window, "Failed to create window!");
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		SetVSync(m_WindowProps.VSync);

		SetWindowCallbacks();
		SetKeyboardCallbacks();
		SetMouseCallbacks();
		SetJoystickCallbacks();
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
	void WindowsWindow::SetWindowCallbacks()
	{
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window))
				->InvokeCallback(WindowClosedEvent());
		});
		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int state) {
			static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window))
				->InvokeCallback(WindowFocusChangedEvent(state == GLFW_TRUE));
		});
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int w, int h) {
			auto data = static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window));
			data->SetSize(w, h);
			data->InvokeCallback(WindowResizedEvent(w, h));
		});
		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int x, int y) {
			auto data = static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window));
			data->SetPosition(x, y);
			data->InvokeCallback(WindowMovedEvent(x, y));
		});
	}

	void WindowsWindow::SetKeyboardCallbacks()
	{
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			auto data = static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window));
			if (action == GLFW_RELEASE)
				data->InvokeCallback(KeyReleasedEvent(Input::FromGLFWKey(key)));
			else
				data->InvokeCallback(KeyPressedEvent(Input::FromGLFWKey(key), action == GLFW_REPEAT));
		});
	}

	void WindowsWindow::SetMouseCallbacks()
	{
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y) {
			static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window))
				->InvokeCallback(MouseMovedEvent(x, y));
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int key, int action, int mods) {
			auto data = static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window));
			if (action == GLFW_RELEASE)
				data->InvokeCallback(MouseButtonReleasedEvent(Input::FromGLFWMouse(key)));
			else
				data->InvokeCallback(MouseButtonPressedEvent(Input::FromGLFWMouse(key)));
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double x, double y) {
			static_cast<WindowsWindow *>(glfwGetWindowUserPointer(window))
				->InvokeCallback(MouseScrolledEvent(x, y));
		});
	}

	void WindowsWindow::SetJoystickCallbacks()
	{
		// ToDo: Implement joysick events (glfw does not support them so I might need to modify glfw)
	}
}