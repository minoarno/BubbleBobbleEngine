#pragma once
#include "GameObject.h"

class Character final : public  dae::GameObject
{
public:
	Character();
	~Character();

	void SetInput();
private:

};

