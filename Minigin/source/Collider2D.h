#pragma once
#include "BaseComponent.h"

class GameObject;
class Collider2D : public BaseComponent
{
public:
	Collider2D(GameObject* owner);
	~Collider2D();

	virtual void FixedUpdate() override;

	virtual void Render()const override;


private:
	float m_SizeX;
	float m_SizeY;
};

