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
