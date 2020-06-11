#pragma once
#include <string>

class GameObject;
class BaseComponent
{
public:
	BaseComponent(GameObject* owner);
	virtual ~BaseComponent();
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render()const = 0;
	std::string GetTypeName();
protected:
	GameObject* m_OwnerGameObject;
	std::string m_TypeName;
};

