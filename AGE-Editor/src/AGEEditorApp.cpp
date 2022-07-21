#include <AGE.h>
#include <AGE/Core/EntryPoint.h>

#include "EditorLayer.h"


namespace AGE
{
	class AGEEditor : public Application
	{
	public:
		AGEEditor()
			: Application("AGE Editor")
		{
			PushLayer(new EditorLayer());
		}

		~AGEEditor()
		{

		}
	};

	Application* CreateApplication()
	{
		return new AGEEditor();
	}
}


