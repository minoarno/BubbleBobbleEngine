#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <map>

dae::GameObject::GameObject()
	:m_Transform{ new Transform{} }
{
}

dae::GameObject::~GameObject()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		delete component.second;
		component.second = nullptr;
	}
	m_pComponents.clear();
	delete m_Transform;
	m_Transform = nullptr;
}

void dae::GameObject::Start()
{
	for(std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->Start();
	}
}

void dae::GameObject::Update()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->Update();
	}
}

void dae::GameObject::LateUpdate()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->LateUpdate();
	}
}

void dae::GameObject::FixedUpdate()
{
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->FixedUpdate();
	}
}

void dae::GameObject::Render() const
{
	const glm::vec3 pos = m_Transform->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	for (std::pair<std::string, BaseComponent*> component : m_pComponents)
	{
		component.second->Render();
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform->SetPosition(x, y, 0.0f);;
}

void dae::GameObject::AddComponent(BaseComponent* component)
{
	component->SetGameObject(this);
	m_pComponents.emplace(component->GetTypeName(), component);
}

dae::BaseComponent* dae::GameObject::GetComponent(const std::string& name)
{
	if (m_pComponents.find(name) != m_pComponents.end())
	{
		return m_pComponents[name];
	}
	ME_ERROR("GameObject {0} has no component of the type {1}", m_Name, name);
	return nullptr;
}
