#pragma once
#include "BaseComponent.h"
//#include "Transform.h"
#pragma warning(push)
#pragma warning(disable:4201)
#include "glm/vec2.hpp"
#pragma warning(pop)
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

		void AddForce(float x, float y);

		//b2Fixture* AddCollider(const b2FixtureDef& fixtureDef);
	private:
		//friend class Transform;
		bool m_IsStatic = false;
		int m_Weight = 1;

		glm::vec2 m_Velocity = glm::vec2(0.f, 0.f);
		//b2BodyDef m_BodyDef;
		//b2Fixture* m_pFixture;
		//b2Body* m_pBody = nullptr;

		//void AdjustPosition(const glm::vec3& pos);
	};
}