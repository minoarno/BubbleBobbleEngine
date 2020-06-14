#pragma once
#include "BaseComponent.h"
namespace MidestinyEngine
{
	class GameObject;
	class RigidBody : public BaseComponent
	{
	public:
		RigidBody(bool isStatic);
		virtual ~RigidBody();
		RigidBody(const RigidBody& other) = default;
		RigidBody& operator=(const RigidBody& other) = default;
		RigidBody(RigidBody&& other) = default;
		RigidBody& operator=(RigidBody&& other) = default;

		virtual void Start() override;
		virtual void Update() override;
		virtual void FixedUpdate() override;
		virtual void LateUpdate() override;
		virtual void Render() const override;

		b2Fixture* AddCollider(const b2FixtureDef& fixtureDef);
	private:
		bool m_IsStatic = false;
		b2BodyDef m_BodyDef;
		b2Body* m_pBody = nullptr;
	};
}