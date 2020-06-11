#include "MiniginPCH.h"
#include "Transform.h"

dae::Transform::Transform()
	: m_Position{0,0,0}
{
}

dae::Transform::Transform(const glm::vec3& pos)
	: m_Position{ pos }
{
}

dae::Transform::Transform(float x, float y, float z)
	: Transform{ glm::vec3{x,y,z} }
{
}

dae::Transform::~Transform()
{
}

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void dae::Transform::SetPosition(const glm::vec3& pos)
{
	m_Position = pos;
}

void dae::Transform::Translate(float x, float y, float z)
{
	m_Position.x += x;
	m_Position.y += y;
	m_Position.z += z;
}

void dae::Transform::Translate(const glm::vec3& pos)
{
	m_Position += pos;
}