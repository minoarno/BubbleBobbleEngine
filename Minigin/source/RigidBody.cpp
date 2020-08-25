#include "MiniginPCH.h"
#include "ColliderIncludes.h"
#include "Transform.h"
#include "utils.h"

namespace MidestinyEngine
{
	RigidBody::RigidBody(bool isStatic)
	{
		m_TypeName = "RigidBody";
		m_IsStatic = isStatic;
		m_BodyDef.type = (isStatic) ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;
	}

	RigidBody::~RigidBody()
	{
		Scene* scene = m_pOwnerGameObject->GetScene();
		if (scene != nullptr)
		{
			m_pOwnerGameObject->GetScene()->GetWorld()->DestroyBody(m_pBody);
		}
	}

	void RigidBody::Start()
	{
		glm::vec3 pos = m_pOwnerGameObject->GetTransform()->GetPosition();
		m_BodyDef.position = b2Vec2{ pos.x,pos.y };
	
		m_pBody = m_pOwnerGameObject->GetScene()->GetWorld()->CreateBody(&m_BodyDef);
		b2MassData massData = b2MassData{};
		massData.mass = 10;
		m_pBody->SetMassData(&massData);
	}

	void RigidBody::Update()
	{
	}

	void RigidBody::FixedUpdate()
	{
		if (m_IsStatic)return;
		m_pOwnerGameObject->GetComponent<Transform>()->Translate(m_Velocity.x, m_Velocity.y, 0);
		m_Velocity *= 0.85f;
	}

	void RigidBody::LateUpdate()
	{
		static_cast<Transform*>(m_pOwnerGameObject->GetComponent("Transform"))->SetPosThroughRigidBody(MakeVec3(m_pBody->GetPosition()));
	}

	void RigidBody::Render() const
	{
	}

	void RigidBody::AddForce(float x, float y)
	{
		m_Velocity += glm::vec2(x, y);
	}

	b2Fixture* RigidBody::AddCollider(const b2FixtureDef& fixtureDef)
	{
		m_pFixture = m_pBody->CreateFixture(&fixtureDef);
		return m_pFixture;
	}

	void RigidBody::AdjustPosition(const glm::vec3& pos)
	{
		if (m_pBody != nullptr)
		{
			m_pBody = m_pOwnerGameObject->GetScene()->GetWorld()->CreateBody(&m_BodyDef);
		}
		else
		{
			m_BodyDef.position = b2Vec2{ pos.x,pos.y };
		}
	}
}