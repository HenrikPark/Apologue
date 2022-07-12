#include <AGE.h>

#include <Platform/OpenGl/OpenGLShader.h>

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>





class ExampleLayer : public AGE::Layer
{
public:
	ExampleLayer()
		:Layer("Example"), m_CameraController(1280.0f / 720.0f, true)
	{	
		m_VertexArray.reset(AGE::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		AGE::Ref<AGE::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(AGE::VertexBuffer::Create(vertices, sizeof(vertices)));

		AGE::BufferLayout layout = {
			{AGE::ShaderDataType::Float3, "a_Position"},
			{AGE::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0,1,2 };
		AGE::Ref<AGE::IndexBuffer> indexBuffer;
		indexBuffer.reset(AGE::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(AGE::VertexArray::Create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		AGE::Ref<AGE::VertexBuffer> squareVB;
		squareVB.reset(AGE::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ AGE::ShaderDataType::Float3, "a_Position" },
			{ AGE::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		AGE::Ref<AGE::IndexBuffer> squareIB;
		squareIB.reset(AGE::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;			
			layout(location = 1) in vec4 a_Color;			
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}

		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color; 
			}

		)";

		m_Shader = AGE::Shader::Create("VertexPosColor",vertexSrc, fragmentSrc);

		std::string flatColorShadervertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
						
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;		
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;				
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}

		)";

		std::string flatColorShaderfragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;	

			uniform vec3 u_Color;		

			void main()
			{
				color = vec4(u_Color, 1.0);				
			}

		)";



		m_FlatColorShader = AGE::Shader::Create("FlatColor",flatColorShadervertexSrc, flatColorShaderfragmentSrc);

		auto textureShader = m_shaderLibrary.Load( "assets/shaders/Texture.glsl");

		m_Texture = (AGE::Texture2D::Create("assets/textures/Checkerboard.png"));
		m_AGELogoTexture = (AGE::Texture2D::Create("assets/textures/AGELogo.png"));

		std::dynamic_pointer_cast<AGE::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<AGE::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(AGE::Timestep ts) override
	{
		//Update
		float deltaTime = ts;
		m_CameraController.onUpdate(deltaTime);



		//Render
		AGE::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		AGE::RenderCommand::Clear();

		AGE::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<AGE::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<AGE::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (size_t x = 0; x < 20; x++)
		{
			for (size_t y = 0; y < 20; y++)
			{
				glm::vec3 pos(x * 0.11f, y *0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos ) * scale;
				AGE::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_shaderLibrary.Get("Texture");

		m_Texture->Bind();
		AGE::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_AGELogoTexture->Bind();
		AGE::Renderer::Submit(textureShader, m_SquareVA,glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		//triangle
		//AGE::Renderer::Submit(m_Shader, m_VertexArray);

		AGE::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{	
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(AGE::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}


private:
	
	AGE::ShaderLibrary m_shaderLibrary;
	AGE::Ref<AGE::Shader> m_Shader;
	AGE::Ref<AGE::VertexArray>  m_VertexArray;
	
	AGE::Ref<AGE::Shader> m_FlatColorShader;
	AGE::Ref<AGE::VertexArray>  m_SquareVA;

	AGE::Ref<AGE::Texture2D> m_Texture;
	AGE::Ref<AGE::Texture2D> m_AGELogoTexture;

	AGE::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};


class Sandbox : public AGE::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		
	}
	~Sandbox()
	{

	}

};
AGE::Application* AGE::CreateApplication()
{
	return new Sandbox();
}