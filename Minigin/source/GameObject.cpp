#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <map>

dae::GameObject::GameObject()
	:m_Transform{ new Transform{} }
{
}

dae::GameObject::~GameObject() = default;

void dae::GameObject::Start()
{
}

void dae::GameObject::Update()
{
}

void dae::GameObject::LateUpdate()
{
}

void dae::GameObject::FixedUpdate()
{
}

void dae::GameObject::Render() const
{
	auto pos = m_Transform->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
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
