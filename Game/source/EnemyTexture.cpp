#include "MiniginPCH.h"
#include "EnemyTexture.h"
#include "Enums.h"
#include "BaseEnemy.h"

void EnemyTexture::SetTexture(const std::string& filepath)
{
}

void EnemyTexture::Start()
{
	m_ImageWidth = m_pTexture->GetWidth() / float(m_AmountOfFrames);
	m_ImageHeight = m_pTexture->GetHeight() / 3.f;
	int cooldown = int(1000.f / m_FramesPerSec);
	Invoke(std::bind(&EnemyTexture::IncrementAnimationCounter, this), cooldown, true);
}

void EnemyTexture::Update()
{
	switch (m_pBaseEnemy->GetEnemyState())
	{
	case EnemyState::walking:
		m_AnimationCounter %= m_AmountOfWalkingFrames;
		break;
	case EnemyState::trapped:
		m_AnimationCounter %= m_AmountOfBeingTrappedFrames;
		break;
	case EnemyState::dying:
		m_AnimationCounter %= m_AmountOfDyingFrames;
		break;
	default:
		break;
	}
}

void EnemyTexture::IncrementAnimationCounter()
{
	m_AnimationCounter++;
}

void EnemyTexture::Render() const
{
}

void EnemyTexture::ResetAnimationCounter()
{
}
