#include "AGEpch.h"
#include "OrthographicCameraController.h"

#include "AGE/Core/Input.h"
#include "AGE/Core/KeyCodes.h"

namespace AGE
{
	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		:m_AspectRatio(aspectRatio), m_Bounds({ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }),m_Camera(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top), m_Rotation(rotation)
	{
	}
	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		AGE_PROFILE_FUNCTION();
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
		AGE_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(AGE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(AGE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	void OrthographicCameraController::OnResize(float width, float height)
	{
		m_AspectRatio = width / height;
		CalculateView();
	}

	void OrthographicCameraController::CalculateView()
	{
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		AGE_PROFILE_FUNCTION();

		m_ZoomLevel -= e.GetYOffset() * m_CameraZoomSpeed;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		CalculateView();
		return false;
	}
	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		AGE_PROFILE_FUNCTION();

		OnResize((float)e.GetWidth(), (float)e.GetHeight());
		CalculateView();
		return false;
	}
}