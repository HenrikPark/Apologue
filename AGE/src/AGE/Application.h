#pragma once

#include "Core.h"

#include "Window.h"
#include "AGE/LayerStack.h"
#include "AGE/Events/Event.h"
#include "AGE/Events/ApplicationEvent.h"

#include "AGE/ImGui/ImGuiLayer.h"

#include "AGE/Renderer/Shader.h"
#include "AGE/Renderer/Buffer.h"
#include "AGE/Renderer/VertexArray.h"

#include "AGE/Renderer/OrthographicCamera.h"


namespace AGE
{
	class AGE_API Application
	{
	public:
		Application();
		virtual ~Application();	

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;		

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray>  m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray>  m_SquareVA;

		OrthographicCamera m_Camera;

	private:
		static Application* s_Instance;
	};

	//To be Defined in client
	Application* CreateApplication();

}

