#include "MiniginPCH.h"
#include "BoxCollider.h"

namespace dae
{
	BoxCollider::BoxCollider()
		: BaseComponent{}
	{
		m_TypeName = "Collider2D";

		m_pBodyshape->SetAsBox(20, 20);
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

	void BoxCollider::FixedUpdate()
	{

	}

	void BoxCollider::Render() const
	{
	}
}