#pragma once

#include "entt.hpp"

namespace AGE
{
	class Scene
	{
	public:
		Scene();
		~Scene();
	private:
		entt::registry m_Registry;
	};
}