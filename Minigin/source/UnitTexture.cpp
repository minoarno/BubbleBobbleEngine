#include "MiniginPCH.h"
#include "UnitTexture.h"
#include "GameObject.h"
#include "ResourceManager.h"

UnitTexture::UnitTexture()
{
}

UnitTexture::UnitTexture(dae::GameObject* gameObject, const std::string& filepath, int amountOfFrames)
{
	SetGameObject(gameObject);
	SetTexture(filepath);
	m_AmountOfFrames = amountOfFrames;
}

UnitTexture::~UnitTexture()
{
}

void UnitTexture::Update()
{
}

void UnitTexture::Render() const
{
	//int number{ (int(m_pAvatar->GetStance()) + 1) + int(m_pAvatar->GetActionState()) * m_AmountOfStances };
	//Rectf srcRect{ m_AnimCounter * m_ImageWidth, number * m_ImageHeight, m_ImageWidth, m_ImageHeight };

	//m_pTexture->Draw(destRect, srcRect);
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


