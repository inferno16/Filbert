#pragma once
#include "Window.h"

#include <GLFW/glfw3.h>

namespace Filbert
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow();
		~WindowsWindow();
		virtual void Update() override;

		void Init();
		void Destroy();
		inline virtual void* GetNativeWindow() const override { return static_cast<void*>(m_Window); };
		virtual void SetVSync(const bool& state) override;
	private:
		void SetWindowCallbacks();
		void SetKeyboardCallbacks();
		void SetMouseCallbacks();
		void SetJoystickCallbacks();
	private:
		GLFWwindow* m_Window;
		static bool s_GLFWInitialized;
	};
}