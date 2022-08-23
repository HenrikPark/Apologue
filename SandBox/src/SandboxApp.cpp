#include <AGE.h>
#include <AGE/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public AGE::Application
{
public:
	Sandbox(const AGE::ApplicationSpecification& specification)
		: AGE::Application(specification)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

AGE::Application* AGE::CreateApplication(AGE::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../AGE-Editor";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}