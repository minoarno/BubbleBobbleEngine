#include "MiniginPCH.h"
#include "BoxCollider.h"

namespace dae
{
	BoxCollider::BoxCollider()
		: BaseComponent{}
	{
		m_TypeName = "BoxCollider";

		m_pBodyshape->SetAsBox(20, 20);
	}

	BoxCollider::~BoxCollider()
	{
		delete m_pBodyshape;
		m_pBodyshape = nullptr;

		delete m_pFixture;
		m_pFixture = nullptr;
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