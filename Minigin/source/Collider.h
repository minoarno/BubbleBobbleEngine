#pragma once
#include "BaseComponent.h"

class GameObject;
class Collider : public BaseComponent
{
public:
	Collider(GameObject* owner);
	~Collider();

	virtual void FixedUpdate() override;


private:
	float m_SizeX;
	float m_SizeY;
	float m_SizeZ;
};

