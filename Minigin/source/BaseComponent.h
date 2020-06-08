#pragma once
class GameObject;
class BaseComponent
{
public:
	BaseComponent(GameObject* owner);
	virtual ~BaseComponent();
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update(float elapsedSeconds) = 0;
	virtual void LateUpdate(float elapsedSeconds) = 0;
protected:
	GameObject* m_OwnerGameObject;
};

