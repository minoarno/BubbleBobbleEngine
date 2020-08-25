#include "Projectile.h"
#include "utils.h"
#include "SceneObject.h"

void Projectile::Start()
{
}

void Projectile::Update()
{
}

void Projectile::LateUpdate()
{
}

void Projectile::FixedUpdate()
{
}

void Projectile::Render() const
{
}

bool Projectile::DoesProjectileHit(MidestinyEngine::SceneObject* sceneObject)
{
	if (sceneObject != m_OwnerObject)
	{
		if (sceneObject->GetTag() != "")
		{
			if (MidestinyEngine::IsOverlapping(static_cast<MidestinyEngine::GameObject*>(sceneObject)->GetBoundaries(), this->GetBoundaries()))
			{
				m_HasAlreadyHit = true;
				return true;
			}
		}
	}
	return false;
}