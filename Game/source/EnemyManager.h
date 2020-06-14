#pragma once
#include "Singleton.h"

namespace MidestinyEngine
{
	class BaseEnemy;
	class EnemyManager : public MidestinyEngine::Singleton<EnemyManager>
	{
		~EnemyManager();

		void Update();
		void LateUpdate();
		void FixedUpdate();
		void Render();

		void AddEnemy(BaseEnemy* enemy) { m_pEnemies.push_back(enemy); }
	private:
		friend class MidestinyEngine::Singleton<EnemyManager>;
		EnemyManager() = default;

		std::vector<BaseEnemy*> m_pEnemies;
	};
}