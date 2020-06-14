#include "MiniginPCH.h"
#include "ColliderIncludes.h"

namespace MidestinyEngine
{
	RigidBody::RigidBody(bool isStatic)
	{
		m_TypeName = "RigidBody";
		m_BodyDef.type = (isStatic) ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;
	}

	RigidBody::~RigidBody()
	{
		m_pOwnerGameObject->GetScene()->GetWorld()->DestroyBody(m_pBody);
	}

	void RigidBody::Start()
	{
		glm::vec3 pos = m_pOwnerGameObject->GetTransform()->GetPosition();
		m_BodyDef.position = b2Vec2{ pos.x,pos.y };
		m_pBody = m_pOwnerGameObject->GetScene()->GetWorld()->CreateBody(&m_BodyDef);
	}

	void RigidBody::Update()
	{
	}

	void RigidBody::FixedUpdate()
	{
	}

	void RigidBody::LateUpdate()
	{
	}

	void RigidBody::Render() const
	{
	}

	b2Fixture* RigidBody::AddCollider(const b2FixtureDef& fixtureDef)
	{
		return m_pBody->CreateFixture(&fixtureDef);
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