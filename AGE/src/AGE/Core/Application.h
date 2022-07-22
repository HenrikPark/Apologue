#pragma once

#include "Base.h"

#include "Window.h"
#include "AGE/Core/LayerStack.h"
#include "AGE/Events/Event.h"
#include "AGE/Events/ApplicationEvent.h"

#include "AGE/Core/Timestep.h"

#include "AGE/ImGui/ImGuiLayer.h"


namespace AGE
{
	class Application
	{
	public:
		Application(const std::string& name = "AGE App");
		virtual ~Application();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }

		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	//To be Defined in client
	Application* CreateApplication();

}

