#pragma once
class GameObject;
class BaseComponent
{
public:
	BaseComponent(GameObject* owner);
	virtual ~BaseComponent();
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void LateUpdate() = 0;
protected:
	GameObject* m_OwnerGameObject;
};

