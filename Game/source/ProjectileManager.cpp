#include "ProjectileManager.h"
#include "Projectiles.h"
#include "Scene.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Scene.h"

using namespace MidestinyEngine;

ProjectileManager::~ProjectileManager()
{
	Clear();
}

void ProjectileManager::Update()
{
	for (Projectile* pProjectile : m_pProjectiles)
	{
		if (pProjectile != nullptr)
		{
			pProjectile->Update();
			for (MidestinyEngine::SceneObject* sceneObject: MidestinyEngine::SceneManager::GetInstance().GetActiveScene()->GetObjectsInScene() )
			{
				if (sceneObject != nullptr)
				{
					pProjectile->DoesProjectileHit(sceneObject);
				}
			}
		}
	}

	std::vector<Projectile*>::iterator it = std::remove_if(m_pProjectiles.begin(), m_pProjectiles.end(), [](Projectile* p)
	{
		if (p->GetAlreadyHit())
		{
			delete p;
			p = nullptr;
			return true;
		}
		return false;
	});
	m_pProjectiles.erase(it, m_pProjectiles.end());
}

void ProjectileManager::Clear()
{
	for (Projectile* projectile : m_pProjectiles)
	{
		delete projectile;
		projectile = nullptr;
	}
	m_pProjectiles.clear();
}