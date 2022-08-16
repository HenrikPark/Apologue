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
	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			AGE_CORE_ASSERT(index < Count,"Index is less than Count");
			return Args[index];
		}
	};

	class Application
	{
	public:
		Application(const std::string& name = "Hazel App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }

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
		ApplicationCommandLineArgs m_CommandLineArgs;
	private:
		static Application* s_Instance;
	};

	//To be Defined in client
	Application* CreateApplication(ApplicationCommandLineArgs args);

}

