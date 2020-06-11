#include "MiniginPCH.h"
#include "Collider2D.h"
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_world.h>
#include <box2d/b2_collision.h>
#include <box2d/b2_fixture.h>

Collider2D::Collider2D(GameObject* owner)
	: BaseComponent{owner}
	, m_SizeX{1.f}
	, m_SizeY{1.f}
{
	m_TypeName = "Collider2D";
}

Collider2D::~Collider2D()
{

}

void Collider2D::FixedUpdate()
{

}

void Collider2D::Render() const
{
}