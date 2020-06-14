#include "MiniginPCH.h"
#include "UnitTexture.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Texture2D.h"
#include "Character.h" 
UnitTexture::UnitTexture()
	:m_DestinationRectangle{ Rectf{} }
{
}

UnitTexture::UnitTexture(MidestinyEngine::GameObject* gameObject, const std::string& filepath, int amountOfFrames)
{
	SetGameObject(gameObject);
	SetTexture(filepath);
	m_AmountOfFrames = amountOfFrames;
}

UnitTexture::~UnitTexture()
{
}

void UnitTexture::Start()
{
	m_ImageWidth = m_pTexture->GetWidth() / float(m_AmountOfFrames);

	m_ImageHeight = m_pTexture->GetHeight() / 3.f;
}

void UnitTexture::Update()
{
}

void UnitTexture::Render() const
{
	int number = int(m_pCharacter->GetCharacterState());
	Rectf srcRect{ m_AnimationCounter * m_ImageWidth, number * m_ImageHeight, m_ImageWidth, m_ImageHeight };

	m_pTexture->GetSDLTexture(); //Draw(m_DestinationRectangle, srcRect);
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