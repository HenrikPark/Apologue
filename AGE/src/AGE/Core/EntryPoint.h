#pragma once

#ifdef AGE_PLATFORM_WINDOWS

extern AGE::Application* AGE::CreateApplication();

int main(int argc, char** argv)
{
	
	AGE::Log::Init();
	AGE_PROFILE_BEGIN_SESSION("Startup", "AGEProfile-Startup.json");
	auto app = AGE::CreateApplication();
	AGE_PROFILE_END_SESSION();

	AGE_PROFILE_BEGIN_SESSION("Runtime", "AGEProfile-Runtime.json");
	app->Run();
	AGE_PROFILE_END_SESSION();

	AGE_PROFILE_BEGIN_SESSION("Shutdown", "AGEProfile-Shutdown.json");
	delete app;
	AGE_PROFILE_END_SESSION();
}


#endif