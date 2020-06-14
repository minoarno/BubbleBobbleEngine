#include "MiniginPCH.h"
#include "EnemyTexture.h"
#include "Enums.h"
#include "BaseEnemy.h"
#include "ResourceManager.h"

void EnemyTexture::Start()
{
	m_ImageWidth = m_pTexture->GetWidth() / float(m_AmountOfFrames);
	m_ImageHeight = m_pTexture->GetHeight() / 8.f;
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
	int stateIndex = int(m_pBaseEnemy->GetEnemyState());
	int typeIndex = int(m_pBaseEnemy->GetEnemyType());
	Rectf srcRect{ (stateIndex * 4 + m_AnimationCounter) * m_ImageWidth, typeIndex * m_ImageHeight, m_ImageWidth, m_ImageHeight };

	Renderer::GetInstance().RenderTexture(*m_pTexture, srcRect, m_pBaseEnemy->GetBoundaries());
}

void EnemyTexture::ResetAnimationCounter()
{
	m_AnimationCounter = 0;
	m_AnimationTimer = 0;
}

void EnemyTexture::SetTexture(const std::string& filepath)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filepath);
}