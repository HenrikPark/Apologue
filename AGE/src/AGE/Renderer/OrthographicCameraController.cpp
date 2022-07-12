#include "AGEpch.h"
#include "OrthographicCameraController.h"

#include "AGE/Core/Input.h"
#include "AGE/Core/KeyCodes.h"

namespace AGE
{
	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		:m_AspectRatio(aspectRatio),m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio* m_ZoomLevel,-m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{
	}
	void OrthographicCameraController::onUpdate(Timestep ts)
	{
		//Move Camera
		float aDeltaTime = ts; //TGA Way to do it

		if (Input::IsKeyPressed(AGE_KEY_A))
		{
			m_CameraPosition.x -= m_CameraTranslationSpeed * aDeltaTime;
		}
		else if (Input::IsKeyPressed(AGE_KEY_D))
		{
			m_CameraPosition.x += m_CameraTranslationSpeed * aDeltaTime;
		}
		if (Input::IsKeyPressed(AGE_KEY_W))
		{
			m_CameraPosition.y += m_CameraTranslationSpeed * aDeltaTime;
		}
		else if (Input::IsKeyPressed(AGE_KEY_S))
		{
			m_CameraPosition.y -= m_CameraTranslationSpeed * aDeltaTime;
		}

		if (m_Rotation)
		{
			if (Input::IsKeyPressed(AGE_KEY_Q))
			{
				m_CameraRotation += m_CameraRotationSpeed * aDeltaTime;
			}
			else if (Input::IsKeyPressed(AGE_KEY_E))
			{
				m_CameraRotation -= m_CameraRotationSpeed * aDeltaTime;
			}
			m_Camera.SetRotation(m_CameraRotation);
		}		
		m_Camera.SetPosition(m_CameraPosition);
		//sets camera to move slower the more u zoom in
		m_CameraTranslationSpeed = m_ZoomLevel;
	}
	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(AGE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(AGE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}
	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset() * m_CameraZoomSpeed;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}