#pragma once

#include "Layer.h"

namespace Filbert {

	class FLB_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		Layer* PopLayer();
		void RemoveLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		Layer* PopOverlay();
		void RemoveOverlay(Layer* layer);
		void Destroy();

		void OnUpdate();
		void OnEvent(Event& e);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		void _CleanUp();

	private:
		std::vector<Layer*>::iterator m_LayerInsert;
		std::vector<Layer*> m_Layers;
	};
}
