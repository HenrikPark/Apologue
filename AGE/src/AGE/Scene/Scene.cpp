#include "AGEpch.h"
#include "Scene.h"

#include <glm/glm.hpp>

namespace AGE
{
	static void OnTransformConstruct(entt::registry& registry, entt::entity entity)
	{

	}

	Scene::Scene()
	{
		struct MeshComponent
		{

		};
		struct TransformComponent
		{
			glm::mat4 Transform;

			TransformComponent() = default;
			TransformComponent(const TransformComponent&) = default;
			TransformComponent(const glm::mat4& transform)
				:Transform(transform)	{}

			operator glm::mat4& () { return Transform; }
			operator const glm::mat4& () const { return Transform; }
		};

		//Kallar en function när transformcomponent skapas
		m_Registry.on_construct<TransformComponent>().connect<&OnTransformConstruct>();

		//skapa Entitiy
		entt::entity entity = m_Registry.create();
		//lägg till en component
		m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));
		//OM en entity har en komponent
		if (m_Registry.all_of<TransformComponent>(entity))
		{
			//Hämta den komponenten
			TransformComponent& transform = m_Registry.get<TransformComponent>(entity);
		}
		//leta upp alla entitys med en speciell component
		auto view = m_Registry.view<TransformComponent>();
		//gå igenom alla entitys med den componenten
		for (auto entity : view)
		{
			TransformComponent& transform = view.get<TransformComponent>(entity);
		}

		//Om du söker entitys med FLERA componenter
		auto group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
		for (auto entity : group)
		{
			auto& transform = group.get<TransformComponent, MeshComponent>(entity);
		}
	}
	Scene::~Scene()
	{
	}
}