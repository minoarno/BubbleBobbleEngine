#pragma once

#include "Core.h"
struct SDL_Window;

namespace MidestinyEngine
{
	class /*MIDESTINYENGINE_API*/ Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
		void Cleanup();
	protected:


	private:
		void Initialize();
		void LoadGame();

		const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window;
	};

	//To be defined in client
	Application* CreateApplication();
}