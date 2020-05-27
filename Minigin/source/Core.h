#pragma once

#ifdef MIDESTINYENGINE_PLATFORM_WINDOWS
	#ifdef MIDESTINYENGINE_BUILD_DLL
		#define MIDESTINYENGINE_API __declspec(dllexport)
	#else	
		#define MIDESTINYENGINE_API __declspec(dllimport)
	#endif
#else
	#error The Midestiny Egine only supports Windows!
#endif