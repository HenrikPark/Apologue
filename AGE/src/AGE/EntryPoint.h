#pragma once

#ifdef AGE_PLATFORM_WINDOWS

extern AGE::Application* AGE::CreateApplication();

int main(int argc, char** argv)
{
	
	AGE::Log::Init();
	AGE_CORE_WARN("Initialized Log!");
	int a = 5;
	AGE_INFO("Hello! Var={0}", a);

	auto app = AGE::CreateApplication();
	app->Run();
	delete app;
}


#endif