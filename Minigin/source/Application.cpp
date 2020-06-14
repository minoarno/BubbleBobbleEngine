#include "MiniginPCH.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "TextObject.h"

using namespace MidestinyEngine;
using namespace std::chrono;

MidestinyEngine::Application::Application()
	:m_Window{nullptr}
{
	MidestinyEngine::Application::Initialize();
}

MidestinyEngine::Application::~Application()
{
	MidestinyEngine::Application::Cleanup();
}

void MidestinyEngine::Application::Initialize()
{
	Core::g_WindowWidth = 1024;
	Core::g_WindowHeight = 760;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	m_Window = SDL_CreateWindow
	(
		"Midestiny Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Core::g_WindowWidth,
		Core::g_WindowHeight,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	MidestinyEngine::Renderer::GetInstance().Init(m_Window);

	// tell the resource manager where he can find the game data
	MidestinyEngine::ResourceManager::GetInstance().Init("../Data/");
}

/**
 * Code constructing the scene world starts here
 */
void MidestinyEngine::Application::LoadGame()
{
	MidestinyEngine::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
}

void MidestinyEngine::Application::FixedUpdate()
{
	auto& sceneManager = MidestinyEngine::SceneManager::GetInstance();
	sceneManager.FixedUpdate();
}

void MidestinyEngine::Application::Cleanup()
{
	MidestinyEngine::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void MidestinyEngine::Application::Run()
{
	Core::g_DoContinue = true;

	if(m_Window == nullptr) Initialize();

	LoadGame();
	
	{
		auto& renderer = MidestinyEngine::Renderer::GetInstance();
		auto& sceneManager = MidestinyEngine::SceneManager::GetInstance();
		auto& input = MidestinyEngine::InputManager::GetInstance();
		{
			MidestinyEngine::Invoke(std::bind(&MidestinyEngine::Application::FixedUpdate, this), 1000, true);

			sceneManager.GetActiveScene()->Start();
			while (Core::g_DoContinue)
			{
				const auto currentTime = high_resolution_clock::now();

				Core::g_DoContinue = input.ProcessInput();
				sceneManager.Update();
				renderer.Render();
				sceneManager.LateUpdate();

				MidestinyEngine::GameTime::GetInstance().SetElapsedSeconds(std::chrono::duration<float>(high_resolution_clock::now() - currentTime).count());
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1001));
		}
		MidestinyEngine::SceneManager::GetInstance().SaveScenesToFile("../Data/Scenes.txt");
	}
}