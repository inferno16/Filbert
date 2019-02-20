#pragma once
#include "filbertPCH.h"
#include "Core.h"

namespace Filbert
{
	struct WindowSize { 
		WindowSize(cui32& w, cui32& h) : Width(w), Height(h) {}
		ui32 Width; 
		ui32 Height; 
	};

	struct WindowProperties {
		WindowProperties() : Size(1280, 720), Title("Filbert Engine"), VSync(false) {}
		WindowSize Size;
		std::string Title;
		bool VSync;
	};
	class FLB_API Window
	{
	public:
		virtual ~Window() {}
		virtual void Update() = 0;

		static Window* Create();

		virtual void* GetNativeWindow() = 0;
		virtual void SetVSync(const bool& state) = 0;
		inline bool GetVSync() { return m_WindowProps.VSync; };
		inline WindowSize GetSize() { return m_WindowProps.Size; }
		inline void SetSize(WindowSize& size) { m_WindowProps.Size = size; }
		inline void SetSize(cui32& width, cui32& height) { m_WindowProps.Size = WindowSize(width, height); }
		inline std::string GetTitle() { return m_WindowProps.Title; }
		inline void SetTitle(const std::string& title) { m_WindowProps.Title = title; }

	protected:
		WindowProperties m_WindowProps;
	};
}