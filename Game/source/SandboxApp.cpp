#include <MidestinyEngine.h>
#include "Character.h"
#include "Enemies.h"
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
		Bub->SetPosition(60, 460);
		Bub->SetSize(Core::g_BlockSize * 2, Core::g_BlockSize * 2);
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(Bub);

		ZenChan* zenchan1 = new ZenChan{};
		zenchan1->SetTexture("EnemySpriteSheet.png");
		zenchan1->SetPosition(60, 40); 
		zenchan1->SetSize(Core::g_BlockSize * 2, Core::g_BlockSize * 2);
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(zenchan1);

		ZenChan* zenchan2 = new ZenChan{};
		zenchan1->SetTexture("EnemySpriteSheet.png");
		zenchan1->SetPosition(230, 40);
		zenchan1->SetSize(Core::g_BlockSize * 2, Core::g_BlockSize * 2);
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(zenchan2);

		ZenChan* zenchan3 = new ZenChan{};
		zenchan1->SetTexture("EnemySpriteSheet.png");
		zenchan1->SetPosition(400, 40);
		zenchan1->SetSize(Core::g_BlockSize * 2, Core::g_BlockSize * 2);
		MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->Add(zenchan3);
	}

	~Sandbox() = default;
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}