#include <AGE.h>

#include "imgui/imgui.h"



class ExampleLayer : public AGE::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{	
	}

	void OnUpdate() override
	{
		if (AGE::Input::IsKeyPressed(AGE_KEY_TAB))
		{
			AGE_TRACE("Tab is Pressed!");
		}
	}

	virtual void OnImGuiRender() override
	{

		//Läxan avsnitt 22
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(AGE::Event& event) override
	{
		//AGE_TRACE("{0}", event);
	}
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