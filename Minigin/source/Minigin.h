#pragma once
struct SDL_Window;
namespace dae
{
	class Minigin
	{
	public:
		static void Initialize();
		static void LoadGame();
		static void Cleanup();
		static void Run();
		static void Test();
	private:
		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		static SDL_Window* m_Window;
	};
}