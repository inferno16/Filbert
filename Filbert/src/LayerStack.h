#pragma once

#include "Layer.h"

namespace Filbert {
	typedef std::shared_ptr<Layer> LayerPtr;

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(LayerPtr layer);
		LayerPtr PopLayer();
		void RemoveLayer(LayerPtr layer);
		void PushOverlay(LayerPtr layer);
		LayerPtr PopOverlay();
		void RemoveOverlay(LayerPtr layer);
		void Destroy();

		void OnUpdate();
		void OnEvent(Event& e);

		std::vector<LayerPtr>::iterator begin() { return m_Layers.begin(); }
		std::vector<LayerPtr>::iterator end() { return m_Layers.end(); }

	private:
		ui32 m_LayerInsert;
		std::vector<LayerPtr> m_Layers;
	};
}
