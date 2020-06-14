#pragma once
#include <vector>
#include "EnemyManager.h"
#include "BaseEnemy.h"


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
