#include <MidestinyEngine.h>
#include "Character.h"
#include "ResourceManager.h"

class Sandbox final : public MidestinyEngine::Application
{
public:
	Sandbox()
		:Application()
	{
		MidestinyEngine::SceneManager::GetInstance().LoadScenesFromFile("../Data/Scenes.txt");
		Character* Bub = new Character{};
		Bub->SetTexture("heroGreen.png");
		Bub->SetPosition(60, 200);
		Bub->SetSize(50, 50);
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(Bub);
	}

	~Sandbox() = default;
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}