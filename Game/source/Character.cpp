#include "ColliderIncludes.h"
#include "Character.h"
#include "UnitTexture.h"

int Character::m_AmountOfCharacters{ 0 };

Character::Character()
{
	if (m_pComponents.find("BoxCollider") == m_pComponents.end())
	{
		MidestinyEngine::BoxCollider* boxCollider = new MidestinyEngine::BoxCollider;

		m_pComponents.emplace(boxCollider->GetTypeName(), boxCollider);
	}
	m_AmountOfCharacters++;

	

}

Character::~Character()
{
	MidestinyEngine::GameObject::~GameObject();
}

void Character::Start()
{
}

void Character::Update()
{
}

void Character::LateUpdate()
{
}

void Character::FixedUpdate()
{
}

void Character::Render() const
{
}

void Character::SetTexture(const std::string& filename)
{
	m_pTexture->SetTexture(filename);
	m_pTexture->SetAmountOfFrames(4);
	m_pTexture->SetAmountOfWalkingFrames(4);
	m_pTexture->SetAmountOfDyingFrames(4);
	m_pTexture->SetAmountOfAttackingFrames(2);
}

void Character::SetInput()
{
}