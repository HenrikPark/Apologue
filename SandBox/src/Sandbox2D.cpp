#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>


Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	AGE_PROFILE_FUNCTION();

	m_CheckerBoardTexture = (AGE::Texture2D::Create("assets/textures/Checkerboard.png"));
}

void Sandbox2D::OnDetach()
{
	AGE_PROFILE_FUNCTION();

}


void Sandbox2D::OnUpdate(AGE::Timestep ts)
{
	float deltaTime = ts;	
	AGE_PROFILE_FUNCTION();
	
	//Update
	m_CameraController.OnUpdate(deltaTime);
	

	//Render
	{
		AGE_PROFILE_SCOPE("Renderer Prep");
		AGE::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		AGE::RenderCommand::Clear();
	}

	{
		AGE_PROFILE_SCOPE("Renderer Draw");
		AGE::Renderer2D::BeginScene(m_CameraController.GetCamera());
		AGE::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		AGE::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		AGE::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerBoardTexture);
		AGE::Renderer2D::EndScene();
	}
	
}

void Sandbox2D::OnImGuiRender()
{
	AGE_PROFILE_FUNCTION();
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(AGE::Event& e)
{
	m_CameraController.OnEvent(e);
}
