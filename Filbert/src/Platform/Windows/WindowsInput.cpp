#include "filbertPCH.h"
#include "WindowsInput.h"
#include "Application.h"
#include "GLFW/glfw3.h"

namespace Filbert
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::_IsKeyPressed(const KeyCode& key) const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		return glfwGetKey(window, Input::ToGLFWKey(key)) & (GLFW_PRESS | GLFW_REPEAT);
	}
	bool WindowsInput::_IsMouseButtonPressed(const MouseCode& btn) const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		return glfwGetMouseButton(window, Input::ToGLFWMouse(btn)) == GLFW_PRESS ;
	}
	Vector2<double> WindowsInput::_GetMousePosition() const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		Vector2<double> pos;
		glfwGetCursorPos(window, &pos.X, &pos.Y);
		return pos;
	}
}
