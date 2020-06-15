#include "BaseEnemy.h"
#include "EnemyTexture.h"
#include "ColliderIncludes.h"
#include "Log.h"

BaseEnemy::BaseEnemy()
	:m_pTexture{ new EnemyTexture{} }
{
	SetTexture("EnemySpriteSheet.png");
	m_pTexture->SetBaseEnemy(this);
	//if (m_pComponents.find("BoxCollider") == m_pComponents.end())
	//{
		//MidestinyEngine::BoxCollider* boxCollider = new MidestinyEngine::BoxCollider();
		//boxCollider->SetSize(Core::g_BlockSize * 2, Core::g_BlockSize * 2);
		//AddComponent(boxCollider);

		//MidestinyEngine::RigidBody* rigid = new MidestinyEngine::RigidBody(false);
		//AddComponent(rigid);
	//}
}

BaseEnemy::~BaseEnemy()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void BaseEnemy::Start()
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

void BaseEnemy::Update()
{
	m_pTexture->Update();
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->Update();
	}
}

void BaseEnemy::LateUpdate()
{
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->LateUpdate();
	}
}

void BaseEnemy::FixedUpdate()
{
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->FixedUpdate();
	}
}

void BaseEnemy::Render() const
{
	m_pTexture->Render();
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		if (component.second == nullptr)
		{
			ME_CORE_ERROR("");
			continue;
		}
		component.second->Update();
	}
}

void BaseEnemy::SetTexture(const std::string& filename)
{
	m_pTexture->SetTexture(filename);
	m_pTexture->SetAmountOfFrames(12);
	m_pTexture->SetAmountOfWalkingFrames(4);
	m_pTexture->SetAmountOfDyingFrames(4);
	m_pTexture->SetAmountOfBeingTrappedFrames(4);
}

void BaseEnemy::GoTowardsThePlayer()
{
}


