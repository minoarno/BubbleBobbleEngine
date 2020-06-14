#include "MiniginPCH.h"
#include "Transform.h"

MidestinyEngine::Transform::Transform()
	: m_Position{0,0,0}
{
}

MidestinyEngine::Transform::Transform(const glm::vec3& pos)
	: m_Position{ pos }
{
}

MidestinyEngine::Transform::Transform(float x, float y, float z)
	: Transform{ glm::vec3{x,y,z} }
{
}

MidestinyEngine::Transform::~Transform()
{
}

void MidestinyEngine::Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void MidestinyEngine::Transform::SetPosition(const glm::vec3& pos)
{
	m_Position = pos;
}

void MidestinyEngine::Transform::Translate(float x, float y, float z)
{
	m_Position.x += x;
	m_Position.y += y;
	m_Position.z += z;
}

void MidestinyEngine::Transform::Translate(const glm::vec3& pos)
{
	m_Position += pos;
}