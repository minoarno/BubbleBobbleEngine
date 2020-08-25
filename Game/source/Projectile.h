#pragma once
#include "GameObject.h"

class SceneObject;
class Projectile : public MidestinyEngine::GameObject
{
public:
	Projectile() = default;
	virtual ~Projectile() = default;

	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void FixedUpdate() override;
	virtual void Render()const override;

	bool GetAlreadyHit() { return m_HasAlreadyHit; }
	void SetOwnerOfProjectile(MidestinyEngine::GameObject* shooter) { m_OwnerObject = shooter; };

	bool DoesProjectileHit(MidestinyEngine::SceneObject* gameOject);
protected:
	MidestinyEngine::GameObject* m_OwnerObject = nullptr;
	bool m_HasAlreadyHit = false;
};
