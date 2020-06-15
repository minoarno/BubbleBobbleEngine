#include "MiniginPCH.h"
#include "ColliderIncludes.h"
#include "InputManager.h"
#include "Character.h"
#include "UnitTexture.h"
#include "BoxCollider.h"
#include "Commands.h"

Character::Character()
	: GameObject{}
	, m_pTexture{ new UnitTexture{}}
	, m_CharacterState{CharacterState::walking}
{
	m_Tag = "Character";
	m_pTexture->SetCharacter(this);
	//if (m_pComponents.find("BoxCollider") == m_pComponents.end())
	{
		//MidestinyEngine::BoxCollider* boxCollider = new MidestinyEngine::BoxCollider();
		//boxCollider->SetSize(Core::g_BlockSize * 2, Core::g_BlockSize * 2);
		//AddComponent(boxCollider);

		//MidestinyEngine::RigidBody* rigid = new MidestinyEngine::RigidBody(false);
		//AddComponent(rigid);
	}
}

Character::~Character()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Character::Start()
{
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->SetGameObject(this);
	}

	m_pTexture->Start();
	//m_pComponents["RigidBody"]->Start();
	//m_pComponents["BoxCollider"]->Start();
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		if (component.first != "RigidBody" || component.first != "BoxCollider") component.second->Start();
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

void Character::Move(bool isToTheRight)
{
	m_IsToTheRight = isToTheRight;
	float speed = m_Speed * MidestinyEngine::GameTime::GetInstance().GetElapsedSeconds();
	m_Transform->Translate((isToTheRight) ? speed : -speed, 0, 0);
}

void Character::Jump()
{
	GetComponent<MidestinyEngine::RigidBody>()->AddForce(30.f,0.f);
}

void Character::ShootBubble()
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
	MidestinyEngine::InputManager::GetInstance().AddControllerInput(MidestinyEngine::ControllerButton::ButtonA, new FireCommand{});
	MidestinyEngine::InputManager::GetInstance().AddControllerInput(MidestinyEngine::ControllerButton::DPadRight, new WalkRightCommand{});
	MidestinyEngine::InputManager::GetInstance().AddControllerInput(MidestinyEngine::ControllerButton::DPadLeft, new WalkLeftCommand{});
	MidestinyEngine::InputManager::GetInstance().AddControllerInput(MidestinyEngine::ControllerButton::ButtonB, new JumpCommand{});
}
