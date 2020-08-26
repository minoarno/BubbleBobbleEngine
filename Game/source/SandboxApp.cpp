#include <MidestinyEngine.h>
#include "Character.h"
#include "Enemies.h"
#include "ResourceManager.h"
#include "Input.h"
#include "Commands.h"
#include "Transform.h"

class Sandbox final : public MidestinyEngine::Application
{
public:
	Sandbox()
		:Application()
	{
		MidestinyEngine::SceneManager::GetInstance().LoadScenesFromFile("../Data/Levels.txt");
		Character* player1 = new Character{};
		player1->GetTransform()->SetPosition(8 * Core::g_BlockSize,8 * Core::g_BlockSize,0);
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(player1);

		MidestinyEngine::InputManager::GetInstance().AddInput(MidestinyEngine::ControllerButton::ButtonA, new FunctionCommand{ std::bind(&Character::Fire,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(MidestinyEngine::ControllerButton::DPadUp, new FunctionCommand{ std::bind(&Character::MoveUp,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(MidestinyEngine::ControllerButton::DPadDown, new FunctionCommand{ std::bind(&Character::MoveDown,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(MidestinyEngine::ControllerButton::DPadLeft, new FunctionCommand{ std::bind(&Character::MoveLeft,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(MidestinyEngine::ControllerButton::DPadRight, new FunctionCommand{ std::bind(&Character::MoveRight,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(SDL_SCANCODE_SPACE, new FunctionCommand{ std::bind(&Character::Fire,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(SDL_SCANCODE_UP, new FunctionCommand{ std::bind(&Character::MoveUp,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(SDL_SCANCODE_DOWN, new FunctionCommand{ std::bind(&Character::MoveDown,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(SDL_SCANCODE_LEFT, new FunctionCommand{ std::bind(&Character::MoveLeft,player1) });
		MidestinyEngine::InputManager::GetInstance().AddInput(SDL_SCANCODE_RIGHT, new FunctionCommand{ std::bind(&Character::MoveRight,player1) });
	}

	~Sandbox() = default;
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}