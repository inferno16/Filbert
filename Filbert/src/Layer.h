#pragma once

#include "Events/Event.h"

namespace Filbert {

	class Layer
	{
	public:
		Layer(const std::string& name);
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}
		inline std::string GetName() const { return m_Name; }
	private:
		std::string m_Name;
	};
}
