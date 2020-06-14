#include "MiniginPCH.h"
#include "Transform.h"

MidestinyEngine::Transform::Transform()
	: m_Position{0,0,0}
{
	m_TypeName = "Transform";
}

MidestinyEngine::Transform::Transform(const glm::vec3& pos)
	: m_Position{ pos }
{
}

MidestinyEngine::Transform::Transform(float x, float y, float z)
	: Transform{ glm::vec3{x,y,z} }
{
}

void MidestinyEngine::Transform::Start()
{
}

void MidestinyEngine::Transform::Update()
{
}

void MidestinyEngine::Transform::LateUpdate()
{
}

void MidestinyEngine::Transform::FixedUpdate()
{
}

void MidestinyEngine::Transform::Render() const
{
}

void MidestinyEngine::Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
	RigidBody* rigidBody = static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"));
	if (rigidBody != nullptr)
	{
		rigidBody->AdjustPosition(m_Position);
	}
}

void MidestinyEngine::Transform::SetPosition(const glm::vec3& pos)
{
	m_Position = pos;
	RigidBody* rigidBody = static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"));
	if (rigidBody != nullptr)
	{
		rigidBody->AdjustPosition(m_Position);
	}
}

void MidestinyEngine::Transform::Translate(float x, float y, float z)
{
	m_Position.x += x;
	m_Position.y += y;
	m_Position.z += z;
	static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"))->AdjustPosition(m_Position);
}

void MidestinyEngine::Transform::Translate(const glm::vec3& pos)
{
	m_Position += pos;
	static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"))->AdjustPosition(m_Position);
}