#include <MidestinyEngine.h>
#include "EnemyManager.h"
#include "BaseEnemy.h"

namespace MidestinyEngine
{
	EnemyManager::~EnemyManager()
	{
		for (BaseEnemy* enemy : m_pEnemies)
		{
			delete enemy;
			enemy = nullptr;
		}
		m_pEnemies.clear();
	}

	void EnemyManager::Update()
	{
	}

	void EnemyManager::LateUpdate()
	{
	}

	void EnemyManager::FixedUpdate()
	{
	}

	void EnemyManager::Render()
	{
	}
}