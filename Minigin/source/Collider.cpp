#include "MiniginPCH.h"
#include "Collider.h"

Collider::Collider(GameObject* owner)
	: BaseComponent{owner}
	, m_SizeX{1.f}
	, m_SizeY{1.f}
	, m_SizeZ{1.f}
{
}

Collider::~Collider()
{
}

void Collider::FixedUpdate()
{
}
