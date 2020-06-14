#include <MidestinyEngine.h>
#include "Character.h"
#include "ResourceManager.h"

class Sandbox final : public MidestinyEngine::Application
{
public:
	Sandbox()
		:Application()
	{
	}

	~Sandbox() = default;

protected:
	void LoadGame() override
	{
		MidestinyEngine::SceneManager::GetInstance().LoadScenesFromFile("../Data/Scenes.txt");
		Character* Bub = new Character();
		Bub->SetTexture("heroGreen.png");
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(Bub);
	}
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}