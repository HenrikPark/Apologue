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

#ifdef AGE_ENABLE_ASSERTS
	#define AGE_ASSERT(x, ...) {if(!(x)) {AGE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AGE_CORE_ASSERT(x, ...) {if(!(x)) {AGE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AGE_ASSERT(x, ...)
	#define AGE_CORE_ASSERT(x, ...)
#endif 


#define BIT(x) (1 << x)


#define AGE_BIND_EVENT_FN(fn) std::bind(&fn,this, std::placeholders::_1)