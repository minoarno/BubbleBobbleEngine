#include "MiniginPCH.h"
#include "EnemyTexture.h"

void EnemyTexture::SetTexture(const std::string& filepath)
{
}

void EnemyTexture::Start()
{
	m_ImageWidth = m_pTexture->GetWidth() / float(m_AmountOfFrames);
	m_ImageHeight = m_pTexture->GetHeight() / 3.f;
	Invoke(std::bind(&EnemyTexture::IncrementAnimationCounter, this), int(1000.f / m_FramesPerSec), true);
}

void EnemyTexture::Update()
{
	//switch (m_pBaseEnemy->GetEnemyState())
	//{
	//case CharacterState::attack:
	//	m_AnimationCounter %= m_AmountOfAttackingFrames;
	//	break;
	//case CharacterState::walking:
	//	m_AnimationCounter %= m_AmountOfWalkingFrames;
	//	break;
	//case CharacterState::dying:
	//	m_AnimationCounter %= m_AmountOfDyingFrames;
	//	break;
	//default:
	//	break;
	//}
}

void EnemyTexture::IncrementAnimationCounter()
{
}

void EnemyTexture::Render() const
{
}

void EnemyTexture::ResetAnimationCounter()
{
}
