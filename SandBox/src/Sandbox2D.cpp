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
	m_AGELogoTexture = (AGE::Texture2D::Create("assets/textures/AGELogo.png"));
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
	
	AGE::Renderer2D::ResetStats();
	//Render
	{
		AGE_PROFILE_SCOPE("Renderer Prep");
		AGE::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		AGE::RenderCommand::Clear();
	}

	{
		AGE_PROFILE_SCOPE("Renderer Draw");

		static float rotation = 0.0f;
		rotation += deltaTime * 25.0f;

		AGE::Renderer2D::BeginScene(m_CameraController.GetCamera());
		AGE::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		AGE::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		AGE::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		AGE::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerBoardTexture, 10.0f);
		AGE::Renderer2D::DrawRotatedQuad({ 0.0f, 0.5f, 0.0f }, { 1.0f, 1.0f }, rotation, m_AGELogoTexture, 1.0f);
		AGE::Renderer2D::EndScene();

		AGE::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f , 0.75};
				AGE::Renderer2D::DrawQuad({x, y }, { 0.45f, 0.45f }, color);
			}

		}
		AGE::Renderer2D::EndScene();
	}
	
}

void Sandbox2D::OnImGuiRender()
{
	AGE_PROFILE_FUNCTION();
	ImGui::Begin("Settings");

	auto stats = AGE::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(AGE::Event& e)
{
	m_CameraController.OnEvent(e);
}
