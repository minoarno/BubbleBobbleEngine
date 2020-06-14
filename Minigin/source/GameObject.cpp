#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <map>

MidestinyEngine::GameObject::GameObject()
	:m_Transform{ new Transform{} }
{
	m_Transform->SetGameObject(this);
	m_pComponents.emplace(m_Transform->GetTypeName(), m_Transform);
}

MidestinyEngine::GameObject::~GameObject()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		delete component.second;
		component.second = nullptr;
	}
	m_pComponents.clear();
}

void MidestinyEngine::GameObject::Start()
{
	for(std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->Start();
	}
}

void MidestinyEngine::GameObject::Update()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->Update();
	}
}

void MidestinyEngine::GameObject::LateUpdate()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->LateUpdate();
	}
}

void MidestinyEngine::GameObject::FixedUpdate()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->FixedUpdate();
	}
}

void MidestinyEngine::GameObject::Render() const
{
	const glm::vec3 pos = m_Transform->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->Render();
	}
}

void MidestinyEngine::GameObject::SetTexture(const std::string& filename)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
}

void MidestinyEngine::GameObject::SetPosition(float x, float y)
{
	m_Transform->SetPosition(x, y, 0.0f);;
}

void MidestinyEngine::GameObject::AddComponent(BaseComponent* component)
{
	component->SetGameObject(this);
	m_pComponents.emplace(component->GetTypeName(), component);
}

MidestinyEngine::BaseComponent* MidestinyEngine::GameObject::GetComponent(const std::string& name)
{
	if (m_pComponents.find(name) != m_pComponents.end())
	{
		return m_pComponents[name];
	}
	ME_ERROR("GameObject {0} has no component of the type {1}", m_Name, name);
	return nullptr;
}
