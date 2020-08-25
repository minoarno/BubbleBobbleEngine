#pragma once
#include "Singleton.h"
#include <vector>
class Projectile;
class ProjectileManager : MidestinyEngine::Singleton<ProjectileManager>
{
public:
	ProjectileManager() = default;
	ProjectileManager(const ProjectileManager&) = delete;
	ProjectileManager& operator=(const ProjectileManager&) = delete;
	ProjectileManager(ProjectileManager&&) = delete;
	ProjectileManager& operator=(ProjectileManager&&) = delete;
	~ProjectileManager();

	void Update();
	void Clear();
private:
	friend class Singleton;
	std::vector<Projectile*> m_pProjectiles;
};

