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
		inline virtual void* GetNativeWindow() override { return static_cast<void*>(m_Window); };
		virtual void SetVSync(const bool& state) override;
	private:
		GLFWwindow* m_Window;
		static bool s_GLFWInitialized;
	};
}