#include "filbertPCH.h"
#include "LayerStack.h"

namespace Filbert {
	LayerStack::LayerStack()
		: m_LayerInsert(0)
	{
	}


	LayerStack::~LayerStack()
	{
	}

	void LayerStack::PushLayer(LayerPtr layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsert++, layer);
	}

	LayerPtr LayerStack::PopLayer()
	{
		if (m_LayerInsert <= 0) {
			return nullptr;
		}

		LayerPtr layer = m_Layers.at(--m_LayerInsert);
		m_Layers.erase(m_Layers.begin() + m_LayerInsert);
		return layer;
	}

	void LayerStack::RemoveLayer(LayerPtr layer)
	{
		auto begin = m_Layers.begin();
		auto end = m_Layers.end();
		auto it = std::find(begin, end, layer);
		if (it != end && it - begin < m_LayerInsert)
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PushOverlay(LayerPtr layer)
	{
		m_Layers.emplace_back(layer);
	}

	LayerPtr LayerStack::PopOverlay()
	{
		if (m_LayerInsert >= m_Layers.size()) {
			return nullptr;
		}

		LayerPtr layer = m_Layers.back();
		m_Layers.pop_back();
		return layer;
	}

	void LayerStack::RemoveOverlay(LayerPtr layer)
	{
		auto begin = m_Layers.begin() + m_LayerInsert;
		auto it = std::find(begin, m_Layers.end(), layer);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}

	void LayerStack::Destroy()
	{
		m_Layers.erase(m_Layers.begin(), m_Layers.end());
		m_LayerInsert = 0;
	}

	void LayerStack::OnUpdate()
	{
		for (auto layer : m_Layers)
			layer->OnUpdate();
	}

	void LayerStack::OnEvent(Event & e)
	{
		for (auto it = m_Layers.rbegin(); it < m_Layers.rend(); it++) {
			(*it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}
}
