#pragma once
#include <GameObject.h>


class BaseEnemy : public MidestinyEngine::GameObject
{
public:
	BaseEnemy();
	virtual ~BaseEnemy();

	virtual void GoTowardsThePlayer();
protected:
	bool m_HitWithBubble = false;
};
