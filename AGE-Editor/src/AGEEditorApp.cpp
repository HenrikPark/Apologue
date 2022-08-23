#include <AGE.h>
#include <AGE/Core/EntryPoint.h>

#include "EditorLayer.h"


namespace AGE
{
	class AGEEditor : public Application
	{
	public:
		AGEEditor(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}

		~AGEEditor()
		{

		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "AGE-Editor";
		spec.CommandLineArgs = args;

		return new AGEEditor(spec);
	}
}


