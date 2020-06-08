#include "MiniginPCH.h"
#include "BaseComponent.h"

BaseComponent::BaseComponent(GameObject* owner)
	:m_OwnerGameObject{owner}
{
	Awake();
}

BaseComponent::~BaseComponent()
{
}
