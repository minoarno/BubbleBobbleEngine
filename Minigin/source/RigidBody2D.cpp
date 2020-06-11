#include "MiniginPCH.h"
#include "RigidBody2D.h"

RigidBody2D::RigidBody2D(GameObject* owner)
	:BaseComponent{owner}
{
	m_TypeName = "RigidBody2D";
}
