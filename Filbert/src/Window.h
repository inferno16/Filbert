#pragma once
#include "filbertPCH.h"
#include "Core.h"
#include "Events/Event.h"

namespace Filbert
{
	struct WindowSize { 
		WindowSize(cui32& w = 0, cui32& h = 0) : Width(w), Height(h) {}
		ui32 Width; 
		ui32 Height; 
	};

	struct WindowPos {
		WindowPos(cui32& x = 0, cui32& y = 0) : X(x), Y(y) {}
		ui32 X;
		ui32 Y;
	};

	struct WindowProperties {
		WindowProperties() : Size(1280, 720), Title("Filbert Engine"), VSync(false) {}
		WindowSize Size;
		WindowPos Position;
		std::string Title;
		bool VSync;
	};
	class FLB_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}
		virtual void Update() = 0;

		static Window* Create();

		virtual void* GetNativeWindow() const = 0;
		virtual void SetVSync(const bool& state) = 0;
		inline bool GetVSync() const { return m_WindowProps.VSync; };
		inline WindowSize GetSize() const { return m_WindowProps.Size; }
		inline void SetSize(const WindowSize& size) { m_WindowProps.Size = size; }
		inline void SetSize(cui32& width, cui32& height) { m_WindowProps.Size = WindowSize(width, height); }
		inline WindowPos GetPosition() const { return m_WindowProps.Position; }
		inline void SetPosition(const WindowPos& pos) { m_WindowProps.Position = pos; }
		inline void SetPosition(cui32& x, cui32& y) { m_WindowProps.Position = WindowPos(x, y); }
		inline std::string GetTitle() const { return m_WindowProps.Title; }
		inline void SetTitle(const std::string& title) { m_WindowProps.Title = title; }
		inline void SetEventCallback(const EventCallbackFn& function) { m_EventCallback = function; }
		inline void InvokeCallback(Event& e) const { m_EventCallback(e); }

	protected:
		WindowProperties m_WindowProps;
		EventCallbackFn m_EventCallback;
	};
}