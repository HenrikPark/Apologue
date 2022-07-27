#pragma once

#include "AGE/Core/Base.h"
#include "AGE/Core/Log.h"
#include "AGE/Scene/Scene.h"
#include "AGE/Scene/Entity.h"

namespace AGE
{

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}