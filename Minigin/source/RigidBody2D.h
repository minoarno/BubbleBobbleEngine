#pragma once
#include "BaseComponent.h"
class GameObject;
class RigidBody2D : public BaseComponent
{
public:
	RigidBody2D(GameObject* owner);
	virtual ~RigidBody2D();
	RigidBody2D(const RigidBody2D& other) = default;
	RigidBody2D& operator=(const RigidBody2D& other) = default;
	RigidBody2D(RigidBody2D&& other) = default;
	RigidBody2D& operator=(RigidBody2D&& other) = default;

	virtual void Start() override;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void LateUpdate() override;
	virtual void Render() const override;
private:

};