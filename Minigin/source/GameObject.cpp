#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <map>

namespace MidestinyEngine
{
	GameObject::GameObject()
		:m_Transform{ new Transform{} }
	{
		m_Tag = "GameObject";
		m_Transform->SetGameObject(this);
		m_pComponents.emplace(m_Transform->GetTypeName(), m_Transform);
	}

	GameObject::~GameObject()
	{
		for (std::pair<std::string, BaseComponent*> component : m_pComponents)
		{
			delete component.second;
			component.second = nullptr;
		}
		m_pComponents.clear();
	}

	void GameObject::Start()
	{
		for (std::pair<std::string, BaseComponent*> component : m_pComponents)
		{
			component.second->Start();
		}
	}

	void GameObject::Update()
	{
		for (std::pair<std::string, BaseComponent*> component : m_pComponents)
		{
			component.second->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (std::pair<std::string, BaseComponent*> component : m_pComponents)
		{
			component.second->LateUpdate();
		}
	}

	void GameObject::FixedUpdate()
	{
		for (std::pair<std::string, BaseComponent*> component : m_pComponents)
		{
			component.second->FixedUpdate();
		}
	}

	void GameObject::Render() const
	{
		const glm::vec3 pos = m_Transform->GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
		for (std::pair<std::string, BaseComponent*> component : m_pComponents)
		{
			component.second->Render();
		}
	}

	void GameObject::SetTexture(const std::string& filename)
	{
		m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
	}

	void GameObject::SetPosition(float x, float y)
	{
		m_Transform->SetPosition(x, y, 0.0f);;
	}

	void GameObject::AddComponent(BaseComponent* component)
	{
		component->SetGameObject(this);
		m_pComponents.emplace(component->GetTypeName(), component);
	}

	BaseComponent* GameObject::GetComponent(const std::string& name)
	{
		if (m_pComponents.find(name) != m_pComponents.end())
		{
			return m_pComponents[name];
		}
		ME_ERROR("GameObject {0} has no component of the type {1}", m_Name, name);
		return nullptr;
	}

	Rectf GameObject::GetBoundaries() const
	{
		return Rectf{ m_Transform->GetPosition().x, m_Transform->GetPosition().y,m_DestinationRectangle.w,m_DestinationRectangle.h };
	}

	Transform* GameObject::GetTransform() const
	{
		return GetComponent<Transform>();
	}


}

