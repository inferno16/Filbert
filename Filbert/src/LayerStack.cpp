#include "filbertPCH.h"
#include "LayerStack.h"

namespace Filbert {
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}


	LayerStack::~LayerStack()
	{
		_CleanUp();
	}

	void LayerStack::PushLayer(Layer * layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	Layer * LayerStack::PopLayer()
	{
		Layer *layer = *m_LayerInsert;
		m_Layers.erase(m_LayerInsert--);
		return layer;
	}

	void LayerStack::RemoveLayer(Layer* layer)
	{
		auto end = m_LayerInsert + 1;
		auto it = std::find(m_Layers.begin(), end, layer);
		if (it != end)
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		m_Layers.emplace_back(layer);
	}

	Layer * LayerStack::PopOverlay()
	{
		if (m_LayerInsert + 1 == m_Layers.end()) {
			return nullptr;
		}

		Layer *layer = m_Layers.back();
		m_Layers.pop_back();
		return layer;
	}

	void LayerStack::RemoveOverlay(Layer* layer)
	{
		auto begin = m_LayerInsert + 1;
		auto it = std::find(begin, m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}

	void LayerStack::Destroy()
	{
		_CleanUp();
		m_Layers.erase(m_Layers.begin(), m_Layers.end());
		m_LayerInsert = m_Layers.begin();
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

	void LayerStack::_CleanUp()
	{
		for (auto layer : m_Layers)
			delete layer;
	}
}
