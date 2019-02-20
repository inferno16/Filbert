#pragma once

#ifdef FLB_WINDOWS
	#ifdef FLB_BUILD_DLL
		#define FLB_API __declspec(dllexport)
	#else
		#define FLB_API __declspec(dllimport)
	#endif
#else
	#error Unsupported platform!
#endif // FLB_WINDOWS

#ifdef NDEBUG
	#define FLB_ASSERT(x, ...)
	#define FLB_APP_ASSERT(x, ...)
#else
	#define FLB_ASSERT(x, ...)     { if(!(x)) { FLB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FLB_APP_ASSERT(x, ...) { if(!(x)) { FLB_APP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#endif // NDEBUG
#define FLB_VERIFY(x, ...) y=x; FLB_ASSERT(y, __VA_ARGS__)
#define FLB_APP_VERIFY(x, ...) y=x; FLB_APP_ASSERT(y, __VA_ARGS__)