#pragma once
#include <GameObject.h>

class BaseEnemy : public dae::GameObject
{
public:
	BaseEnemy();
	virtual ~BaseEnemy();
protected:
	bool m_HitWithBubble = false;
};

