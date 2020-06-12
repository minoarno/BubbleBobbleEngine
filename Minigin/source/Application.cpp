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
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow
	(
		"Midestiny Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
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
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = new dae::GameObject{};
	go->SetTexture("background.jpg");
	scene.Add(go);

	go = new dae::GameObject{};
	go->SetTexture("logo.png");
	go->SetPosition(216, 180);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = new dae::TextObject("Programming 4 Assignment", font);
	to->SetPosition(80, 20);
	scene.Add(to);
}

void MidestinyEngine::Application::Invoke(std::function<void()> func, int intervalInMilliseconds, bool isLooping)
{
	std::thread([func, intervalInMilliseconds,isLooping]()
	{
		do
		{
			auto nextTimeFunctionCall = std::chrono::steady_clock::now() + std::chrono::milliseconds(intervalInMilliseconds);
			std::this_thread::sleep_until(nextTimeFunctionCall);
			func();
		} while (isLooping);
	}).detach();
}

void MidestinyEngine::Application::FixedUpdate()
{
	auto& sceneManager = dae::SceneManager::GetInstance();
	sceneManager.FixedUpdate();
}

void MidestinyEngine::Application::Cleanup()
{
	dae::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void MidestinyEngine::Application::Run()
{
	if(m_Window == nullptr) Initialize();

	// tell the resource manager where he can find the game data
	dae::ResourceManager::GetInstance().Init("../Data/");

	LoadGame();
	
	{
		auto& renderer = dae::Renderer::GetInstance();
		auto& sceneManager = dae::SceneManager::GetInstance();
		auto& input = dae::InputManager::GetInstance();

		Invoke(std::bind(&MidestinyEngine::Application::FixedUpdate, this), 1000, true);
		
		bool doContinue = true;	
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();

			doContinue = input.ProcessInput();
			sceneManager.Update();
			renderer.Render();
			sceneManager.LateUpdate();
			
			auto sleepTime = duration_cast<duration<float>>(currentTime + milliseconds(MsPerFrame) - high_resolution_clock::now());
			std::this_thread::sleep_for(sleepTime);
		}
	}
}