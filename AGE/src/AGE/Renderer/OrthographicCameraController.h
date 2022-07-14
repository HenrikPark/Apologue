#pragma once

#include <AGE/Renderer/OrthographicCamera.h>
#include "AGE/Core/Timestep.h"

#include "AGE/Events/ApplicationEvent.h"
#include "AGE/Events/MouseEvent.h"

namespace AGE
{
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		float m_CameraZoomSpeed = 0.25;
		OrthographicCamera m_Camera;

		bool m_Rotation;

		glm::vec3 m_CameraPosition = { 0.0f,0.0f,0.0f };
		float m_CameraTranslationSpeed = 5.0f;
		float m_CameraRotation = 0.0f;
		float m_CameraRotationSpeed = 90.0f;
	};
}