#include "MiniginPCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "SDL.h"
#include "Application.h"

#ifdef MIDESTINYENGINE_PLATFORM_WINDOWS

extern MidestinyEngine::Application* MidestinyEngine::CreateApplication();

int main(int, char**)
{
	printf("Midestiny Engine\n");
	auto app = MidestinyEngine::CreateApplication();
	app->Run();
	delete app;
    return 0;
}
#endif