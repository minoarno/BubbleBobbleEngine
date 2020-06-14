#include "MiniginPCH.h"
#include "UnitTexture.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "ThreadMaster.h"
#include "Texture2D.h"
#include "Character.h" 

UnitTexture::UnitTexture(MidestinyEngine::GameObject* gameObject, const std::string& filepath, int amountOfFrames)
{
	SetGameObject(gameObject);
	SetTexture(filepath);
	m_AmountOfFrames = amountOfFrames;
}

void UnitTexture::Start()
{
	m_ImageWidth = m_pTexture->GetWidth() / float(m_AmountOfFrames);
	m_ImageHeight = m_pTexture->GetHeight() / 3.f;
	//MidestinyEngine::ThreadMaster::GetInstance().Invoke(std::bind(&UnitTexture::IncrementAnimationCounter, this), int(1000.f / m_FramesPerSec), true);
}

void UnitTexture::Update()
{
	switch (m_pCharacter->GetCharacterState())
	{
	case CharacterState::attack:
		m_AnimationCounter %= m_AmountOfAttackingFrames;
		break;
	case CharacterState::walking:
		m_AnimationCounter %= m_AmountOfWalkingFrames;
		break;
	case CharacterState::dying:
		m_AnimationCounter %= m_AmountOfDyingFrames;
		break;
	default:
		break;
	}
}

void UnitTexture::IncrementAnimationCounter()
{
	m_AnimationCounter++;
}

void UnitTexture::Render() const
{
	int number = int(m_pCharacter->GetCharacterState());
	Rectf srcRect{ m_AnimationCounter * m_ImageWidth, number * m_ImageHeight, m_ImageWidth, m_ImageHeight };

	Renderer::GetInstance().RenderTexture(*m_pTexture, srcRect, m_pCharacter->GetBoundaries());
	//m_pTexture->GetSDLTexture();
}

void UnitTexture::ResetAnimationCounter()
{
	m_AnimationCounter = 0;
	m_AnimationTimer = 0;
}

void UnitTexture::SetTexture(const std::string& filepath)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filepath);
}