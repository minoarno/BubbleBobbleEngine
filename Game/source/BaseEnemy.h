#pragma once
#include <GameObject.h>
#include "Enums.h"
#include "Structs.h"

class EnemyTexture;
class BaseEnemy : public MidestinyEngine::GameObject
{
public:
	BaseEnemy();
	virtual ~BaseEnemy();

	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void FixedUpdate() override;
	virtual void Render() const override;

	virtual void GoTowardsThePlayer();
	EnemyState GetEnemyState()const { return m_EnemyState; }

	void SetTexture(const std::string& filename) override;
protected:
	EnemyTexture* m_pTexture = nullptr;
	bool m_HitWithBubble = false;
	EnemyState m_EnemyState = EnemyState::walking;
};