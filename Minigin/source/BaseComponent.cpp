#include "MiniginPCH.h"
#include "BaseComponent.h"

BaseComponent::BaseComponent(GameObject* owner)
	: m_OwnerGameObject{owner}
	, m_TypeName{"BaseComponent"}
{
}

BaseComponent::~BaseComponent()
{
}

std::string BaseComponent::GetTypeName()
{
	return m_TypeName;
}
