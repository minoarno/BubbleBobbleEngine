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

namespace Core
{
	static int g_WindowWidth = 1024;
	static int g_WindowHeight = 760;
	static bool g_DoContinue = true;
	static float g_BlockSize = 20.f;
};