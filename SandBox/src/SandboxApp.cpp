#include <AGE.h>


class ExampleLayer : public AGE::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		AGE_INFO("ExampleLayer::Update");
	}

	void OnEvent(AGE::Event& event) override
	{
		AGE_TRACE("{0}", event);
	}
};


class Sandbox : public AGE::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new AGE::ImGuiLayer());
	}
	~Sandbox()
	{

	}

};
AGE::Application* AGE::CreateApplication()
{
	return new Sandbox();
}