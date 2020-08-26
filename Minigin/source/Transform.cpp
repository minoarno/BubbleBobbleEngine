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
	if (m_LevelBoundariesClamp) ClampLevelBoundaries();
	//RigidBody* rigidBody = static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"));
	//if (rigidBody != nullptr)
	//{
	//	rigidBody->AdjustPosition(m_Position);
	//}
}

void MidestinyEngine::Transform::SetPosition(const glm::vec3& pos)
{
	m_Position = pos;
	if (m_LevelBoundariesClamp) ClampLevelBoundaries();
	//RigidBody* rigidBody = static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"));
	//if (rigidBody != nullptr)
	//{
	//	rigidBody->AdjustPosition(m_Position);
	//}
}

void MidestinyEngine::Transform::SetPosThroughRigidBody(const glm::vec3& pos)
{
	m_Position = pos;
	if (m_LevelBoundariesClamp) ClampLevelBoundaries();
}

void MidestinyEngine::Transform::Translate(float x, float y, float z)
{
	m_Position.x += x;
	m_Position.y += y;
	m_Position.z += z;
	if (m_LevelBoundariesClamp) ClampLevelBoundaries();
	//static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"))->AdjustPosition(m_Position);
}

void MidestinyEngine::Transform::Translate(const glm::vec3& pos)
{
	m_Position += pos;
	if (m_LevelBoundariesClamp) ClampLevelBoundaries();
	//static_cast<RigidBody*>(m_pOwnerGameObject->GetComponent("RigidBody"))->AdjustPosition(m_Position);
}

#include "Tilemap.h"
void MidestinyEngine::Transform::ClampLevelBoundaries()
{
	Rectf bounds = MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->GetTilemap()->GetBoundaries();
	if (bounds.x == 0 && bounds.y == 0 && bounds.w == Core::g_BlockSize && bounds.h == Core::g_BlockSize)return;
	if (m_Position.x < bounds.x) m_Position.x = bounds.x;
	else if (m_Position.x + Core::g_BlockSize > bounds.x + bounds.w) m_Position.x = bounds.x + bounds.w - Core::g_BlockSize;

	if (m_Position.y < bounds.y) m_Position.y = bounds.y;
	else if (m_Position.y + Core::g_BlockSize > bounds.y + bounds.h) m_Position.y = bounds.y + bounds.h - Core::g_BlockSize;
}
