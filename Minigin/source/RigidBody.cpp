#include "MiniginPCH.h"
#include "ColliderIncludes.h"

namespace MidestinyEngine
{
	RigidBody::RigidBody(bool isStatic)
	{
		m_TypeName = "RigidBody2D";
		m_BodyDef.type = (isStatic) ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;
	}

	RigidBody::~RigidBody()
	{
	}

	void RigidBody::Start()
	{
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
}