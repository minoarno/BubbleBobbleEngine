#include "MiniginPCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "SDL.h"
#include "Application.h"

#ifdef MIDESTINYENGINE_PLATFORM_WINDOWS

extern MidestinyEngine::Application* MidestinyEngine::CreateApplication();

/*https://docs.microsoft.com/en-us/cpp/preprocessor/hash-undef-directive-c-cpp?view=vs-2019
The #undef directive removes the current definition of identifier. 
Consequently, subsequent occurrences of identifier are ignored by the preprocessor. 
To remove a macro definition using #undef, give only the macro identifier, not a parameter list.*/
#undef main

int main(int, char**)
{
	printf("Midestiny Engine\n");
	auto app = MidestinyEngine::CreateApplication();
	app->Run();
	delete app;
    return 0;
}
#endif