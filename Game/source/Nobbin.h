#pragma once
#include "GameObject.h"

class Nobbin : public MidestinyEngine::GameObject
{
public:
	Nobbin();
	~Nobbin();
private:
	int m_Value = 250;
};

