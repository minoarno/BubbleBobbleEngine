#pragma once
#include "PickUp.h"
class Emerald : public PickUp
{
public:
	Emerald();
	~Emerald();
private:
	int m_Value = 25;
};

