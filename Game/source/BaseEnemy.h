#pragma once
#include <GameObject.h>
#include "Enums.h"

class BaseEnemy : public MidestinyEngine::GameObject
{
public:
	BaseEnemy();
	virtual ~BaseEnemy();

	virtual void GoTowardsThePlayer();
	EnemyState GetEnemyState()const { return m_EnemyState; }
protected:
	bool m_HitWithBubble = false;
	EnemyState m_EnemyState = EnemyState::walking;
};
