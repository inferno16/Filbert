#pragma once
#include "filbertPCH.h"

namespace Filbert
{
	template <typename T1, typename T2>
	class BiMap
	{
	public:
		BiMap(const std::unordered_map<T1, T2>& map);

		inline void Insert(const std::pair<T1, T2>& p) { m_Maps.first.insert(p); m_Maps.second.insert(std::make_pair(p.second, p.first)); }
		inline std::unordered_map<T1, T2> GetLeft() const { return m_Maps.first; }
		inline std::unordered_map<T2, T1> GetRight() const { return m_Maps.second; }
	private:
		std::pair<std::unordered_map<T1, T2>, std::unordered_map<T2, T1>> m_Maps;
	};

	template <typename T1, typename T2>
	BiMap<T1, T2>::BiMap(const std::unordered_map<T1, T2>& map)
	{
		m_Maps.first = map;
		for (auto item : map)
			m_Maps.second.emplace(item.second, item.first);
	}
}