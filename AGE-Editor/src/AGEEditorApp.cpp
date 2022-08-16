#include <AGE.h>
#include <AGE/Core/EntryPoint.h>

#include "EditorLayer.h"


namespace AGE
{
	class AGEEditor : public Application
	{
	public:
		AGEEditor(ApplicationCommandLineArgs args)
			: Application("AGE-Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~AGEEditor()
		{

		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new AGEEditor(args);
	}
}


