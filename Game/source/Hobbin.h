#pragma once
#include "GameObject.h"
class Hobbin : public MidestinyEngine::GameObject
{
public:
	Hobbin();
	~Hobbin();
private:
	int m_Value = 250;
};

