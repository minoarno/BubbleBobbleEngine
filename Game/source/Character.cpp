#include "MiniginPCH.h"
#include "ColliderIncludes.h"
#include "InputManager.h"
#include "Character.h"
#include "UnitTexture.h"
#include "BoxCollider.h"
#include "Commands.h"

Character::Character()
	: GameObject{}
	//, m_pTexture{ new UnitTexture{}}
	//, m_pTexture{nullptr}
	, m_CharacterState{CharacterState::walking}
{
	m_Tag = "Character";
	//m_pTexture->SetCharacter(this);
	SetTexture("Digger.png");
}

Character::~Character()
{
	//delete m_pTexture;
	//m_pTexture = nullptr;
}

void Character::Start()
{
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->SetGameObject(this);
	}

	//if(m_pTexture != nullptr) m_pTexture->Start();

	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->Start();
	}
}

void Character::Update()
{
	//if(m_pTexture != nullptr) m_pTexture->Update();

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
	GameObject::Render();
}

void Character::Move(bool isToTheRight)
{
	m_IsToTheRight = isToTheRight;
	float speed = m_Speed * MidestinyEngine::GameTime::GetInstance().GetElapsedSeconds();
	m_Transform->Translate((isToTheRight) ? speed : -speed, 0, 0);
}

void Character::MoveUp()
{
	float speed = m_Speed * MidestinyEngine::GameTime::GetInstance().GetElapsedSeconds();
	m_Transform->Translate(0, -speed, 0);
	ME_INFO("Move Up");
}

void Character::MoveDown()
{
	float speed = m_Speed * MidestinyEngine::GameTime::GetInstance().GetElapsedSeconds();
	m_Transform->Translate(0, speed, 0);
	ME_INFO("Move Down");
}

void Character::MoveLeft()
{
	float speed = m_Speed * MidestinyEngine::GameTime::GetInstance().GetElapsedSeconds();
	m_Transform->Translate(-speed, 0, 0);
	ME_INFO("Move Left");
}

void Character::MoveRight()
{
	float speed = m_Speed * MidestinyEngine::GameTime::GetInstance().GetElapsedSeconds();
	m_Transform->Translate(speed, 0, 0);
	ME_INFO("Move Right");
}

void Character::Fire()
{
	ME_INFO("Fire");
}

//void Character::SetTexture(const std::string& filename)
//{
//	if (m_pTexture != nullptr)
//	{
//		m_pTexture->SetTexture(filename);
//		m_pTexture->SetAmountOfFrames(4);
//		m_pTexture->SetAmountOfWalkingFrames(4);
//		m_pTexture->SetAmountOfDyingFrames(4);
//		m_pTexture->SetAmountOfAttackingFrames(2);
//	}
//}