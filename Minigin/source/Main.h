#include "MiniginPCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#ifdef MIDESTINYENGINE_PLATFORM_WINDOWS

extern MidestinyEngine::Application* MidestinyEngine::CreateApplication();

/*https://docs.microsoft.com/en-us/cpp/preprocessor/hash-undef-directive-c-cpp?view=vs-2019
The #undef directive removes the current definition of identifier. 
Consequently, subsequent occurrences of identifier are ignored by the preprocessor. 
To remove a macro definition using #undef, give only the macro identifier, not a parameter list.*/
#undef main

int main(int, char**)
{
	MidestinyEngine::Log::Initialize();
	ME_CORE_INFO("Intilialized Log!");

	MidestinyEngine::Application* app = MidestinyEngine::CreateApplication();
	app->Run();
	delete app;
	app = nullptr;
    return 0;
}
#endif