#include <MidestinyEngine.h>
#include "Character.h"
#include "Enemies.h"
#include "ResourceManager.h"
#include "Input.h"
#include "Commands.h"

class Sandbox final : public MidestinyEngine::Application
{
public:
	Sandbox()
		:Application()
	{
		MidestinyEngine::SceneManager::GetInstance().LoadScenesFromFile("../Data/Levels.txt");
		MidestinyEngine::SceneManager::GetInstance().CreateScene("0");
		Character* player1 = new Character{};
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(player1);

		MidestinyEngine::InputManager::GetInstance().AddInput(MidestinyEngine::ControllerButton::ButtonA, new FunctionCommand{ std::bind(&Character::Fire,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(SDL_SCANCODE_SPACE, new FunctionCommand{ std::bind(&Character::Fire,player1) });
	}

	~Sandbox() = default;
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}