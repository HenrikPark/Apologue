#include "AGEpch.h"
#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include <Platform/OpenGl/OpenGLShader.h>

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(AGE::Timestep ts)
{
	//Update
	float deltaTime = ts;
	m_CameraController.onUpdate(deltaTime);



	//Render
	AGE::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	AGE::RenderCommand::Clear();

	AGE::Renderer2D::BeginScene(m_CameraController.GetCamera());

	AGE::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });

	AGE::Renderer2D::EndScene();

	//ToDO: add therse functions - Shaders::SetMat4, Shader::SetFloat4
	//std::dynamic_pointer_cast<AGE::OpenGLShader>(m_FlatColorShader)->Bind();
	//std::dynamic_pointer_cast<AGE::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);	
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(AGE::Event& e)
{
	m_CameraController.OnEvent(e);
}
