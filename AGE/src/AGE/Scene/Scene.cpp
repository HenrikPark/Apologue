#include "AGEpch.h"
#include "Scene.h"

#include "AGE/Renderer/Renderer2D.h"

#include "Components.h"
#include "Entity.h"

#include <glm/glm.hpp>

namespace AGE
{
	static void OnTransformConstruct(entt::registry& registry, entt::entity entity)
	{

	}

	Scene::Scene()
	{
#if ENTT_EXAMPLE_CODE
		//skapa Entitiy
		entt::entity entity = m_Registry.create();
	
		//Kallar en function n?r transformcomponent skapas
		m_Registry.on_construct<TransformComponent>().connect<&OnTransformConstruct>();

		//l?gg till en component
		m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));
		//OM en entity har en komponent
		if (m_Registry.all_of<TransformComponent>(entity))
		{
			//H?mta den komponenten
			TransformComponent& transform = m_Registry.get<TransformComponent>(entity);
		}
		//leta upp alla entitys med en speciell component
		auto view = m_Registry.view<TransformComponent>();
		//g? igenom alla entitys med den componenten
		for (auto entity : view)
		{
			TransformComponent& transform = view.get<TransformComponent>(entity);
		}

		//Om du s?ker entitys med FLERA componenter
		auto group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
		for (auto entity : group)
		{
			auto&[transform, mesh] = group.get<TransformComponent, MeshComponent>(entity);
		}
#endif

	}
	Scene::~Scene()
	{

	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}
	void Scene::OnUpdate(Timestep DeltaTime)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);
			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}
}