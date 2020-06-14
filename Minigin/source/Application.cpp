#include "MiniginPCH.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "TextObject.h"

using namespace dae;
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

	dae::Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void MidestinyEngine::Application::LoadGame()
{
	//auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	//dae::SceneManager::GetInstance().CreateScene("level1");

	//auto go = new dae::GameObject{};
	//go->SetTexture("background.jpg");
	//scene.Add(go);

	//auto go = new dae::GameObject{};
	//go->SetTexture("logo.png");
	//go->SetPosition(216, 180);
	//scene.Add(go);

	dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto to = new dae::TextObject("Programming 4 Assignment", font);
	//to->SetPosition(80, 20);
	//scene.Add(to);
}

void MidestinyEngine::Application::FixedUpdate()
{
	auto& sceneManager = dae::SceneManager::GetInstance();
	sceneManager.FixedUpdate();
}

void MidestinyEngine::Application::Cleanup()
{
	//dae::SceneManager::GetInstance().~SceneManager();
	dae::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void MidestinyEngine::Application::Run()
{
	Core::g_DoContinue = true;

	if(m_Window == nullptr) Initialize();

	// tell the resource manager where he can find the game data
	dae::ResourceManager::GetInstance().Init("../Data/");
	dae::SceneManager::GetInstance().LoadScenesFromFile("../Data/Scenes.txt");
	LoadGame();
	
	{
		auto& renderer = dae::Renderer::GetInstance();
		auto& sceneManager = dae::SceneManager::GetInstance();
		auto& input = dae::InputManager::GetInstance();
		{
			dae::Invoke(std::bind(&MidestinyEngine::Application::FixedUpdate, this), 1000, true);

			while (Core::g_DoContinue)
			{
				const auto currentTime = high_resolution_clock::now();

				Core::g_DoContinue = input.ProcessInput();
				sceneManager.Update();
				renderer.Render();
				sceneManager.LateUpdate();

				//auto sleepTime = duration_cast<duration<float>>(currentTime + milliseconds(MsPerFrame) - high_resolution_clock::now());
				//std::this_thread::sleep_for(sleepTime);
				dae::GameTime::GetInstance().SetElapsedSeconds(std::chrono::duration<float>(high_resolution_clock::now() - currentTime).count());
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1001));
		}
		dae::SceneManager::GetInstance().SaveScenesToFile("../Data/Scenes.txt");
	}
}