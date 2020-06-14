#pragma once
#include "GameObject.h"
#include "Enums.h"

class Drop : public MidestinyEngine::GameObject
{
public:
	Drop() = default;
	~Drop() = default;

	TypeOfDrop GetTypeOfDrop()const { return m_TypeOfDrop; }
private:
	TypeOfDrop m_TypeOfDrop;
};

