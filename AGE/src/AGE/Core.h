#pragma once

#ifdef AGE_PLATFORM_WINDOWS
	#ifdef AGE_BUILD_DLL
		#define AGE_API __declspec(dllexport)
	#else
		#define AGE_API __declspec(dllimport)
	#endif
#else
	#error AGE only support Windows!
#endif