#pragma once

#include "entt.hpp"
#include "AGE/Core/Timestep.h"

namespace AGE
{
	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(Timestep DeltaTime);
	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}