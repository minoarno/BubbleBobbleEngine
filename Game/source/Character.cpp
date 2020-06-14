#include "ColliderIncludes.h"
#include "Character.h"
#include "UnitTexture.h"

Character::Character()
	: m_pTexture{ new UnitTexture{}}
	, m_CharacterState{CharacterState::walking}
	, m_DestinationRectangle{ Rectf{} }
{
	m_pTexture->SetCharacter(this);
	if (m_pComponents.find("BoxCollider") == m_pComponents.end())
	{
		MidestinyEngine::BoxCollider* boxCollider = new MidestinyEngine::BoxCollider();
		boxCollider->SetSize(40, 40);
		m_pComponents.emplace(boxCollider->GetTypeName(), boxCollider);

		MidestinyEngine::RigidBody* rigid = new MidestinyEngine::RigidBody(false);
		m_pComponents.emplace(rigid->GetTypeName(), rigid);
	}
}

Character::~Character()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Character::Start()
{
	m_pTexture->Start();
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->Start();
	}
}

void Character::Update()
{
	m_pTexture->Update();
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->Update();
	}
}

void Character::LateUpdate()
{
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->LateUpdate();
	}
}

void Character::FixedUpdate()
{
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->FixedUpdate();
	}
}

void Character::Render() const
{
	m_pTexture->Render();
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

void Character::SetSize(float width, float height)
{
	m_DestinationRectangle = Rectf{ m_Transform->GetPosition().x, m_Transform->GetPosition().y,50,50 };
}
