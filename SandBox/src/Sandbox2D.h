#pragma once

#include "AGE.h"

class Sandbox2D : public AGE::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(AGE::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(AGE::Event& e) override;
private:
	AGE::OrthographicCameraController m_CameraController;

	//Temp 
	AGE::Ref<AGE::VertexArray>  m_SquareVA;
	AGE::Ref<AGE::Shader> m_FlatColorShader;

	AGE::Ref<AGE::Texture2D> m_CheckerBoardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};