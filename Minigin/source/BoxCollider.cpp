#include "MiniginPCH.h"
#include "BoxCollider.h"

namespace MidestinyEngine
{
	BoxCollider::BoxCollider()
		: BaseComponent{}
	{
		m_TypeName = "BoxCollider";
		m_pBodyshape = new b2PolygonShape();
		m_pBodyshape->SetAsBox(20, 20);

		m_FixtureDef.shape = m_pBodyshape;
		m_FixtureDef.density = 1.f;
	}

	void BoxCollider::Start()
	{
		RigidBody* rigidBody = static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"));
		if (rigidBody == nullptr)
		{
			ME_ERROR("Rigidbody is nullptr");
			return;
		}


		m_pFixture = rigidBody->AddCollider(m_FixtureDef);
	}

	void BoxCollider::Update()
	{

	}

	void BoxCollider::LateUpdate()
	{

	}

	void BoxCollider::FixedUpdate()
	{

	}

	void BoxCollider::Render() const
	{
	}

	void BoxCollider::SetSize(float width, float height)
	{
		m_pBodyshape->SetAsBox(width, height);
	}
}