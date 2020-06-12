#include "MiniginPCH.h"
#include "BaseComponent.h"

namespace dae
{
	BaseComponent::BaseComponent()
		: m_TypeName{ "BaseComponent" }
	{
	}
	BaseComponent::~BaseComponent()
	{
	}

	std::string BaseComponent::GetTypeName()
	{
		return m_TypeName;
	}

	void BaseComponent::SetGameObject(GameObject* owner)
	{
		m_pOwnerGameObject = owner;
	}
}