#pragma once

#ifdef AGE_PLATFORM_WINDOWS

extern AGE::Application* AGE::CreateApplication();

int main(int argc, char** argv)
{
	//printf("Apologue Game Engine...");
	auto app = AGE::CreateApplication();
	app->Run();
	delete app;
}


#endif