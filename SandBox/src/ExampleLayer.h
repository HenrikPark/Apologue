#pragma once

#include "AGE.h"

class ExampleLayer : public AGE::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(AGE::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(AGE::Event& e) override;
private:
	AGE::ShaderLibrary m_ShaderLibrary;
	AGE::Ref<AGE::Shader> m_Shader;
	AGE::Ref<AGE::VertexArray> m_VertexArray;

	AGE::Ref<AGE::Shader> m_FlatColorShader;
	AGE::Ref<AGE::VertexArray> m_SquareVA;

	AGE::Ref<AGE::Texture2D> m_Texture, m_ChernoLogoTexture;

	AGE::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
