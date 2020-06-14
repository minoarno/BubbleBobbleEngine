#include "BaseEnemy.h"
#include "EnemyTexture.h"
#include "Log.h"

BaseEnemy::BaseEnemy()
	:m_pTexture{ new EnemyTexture{} }
{
	m_pTexture->SetBaseEnemy(this);
}

BaseEnemy::~BaseEnemy()
{
}

void BaseEnemy::Start()
{
	m_pTexture->Start();
	for (std::pair<std::string, MidestinyEngine::BaseComponent*> component : m_pComponents)
	{
		component.second->Start();
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

void BaseEnemy::GoTowardsThePlayer()
{
}
