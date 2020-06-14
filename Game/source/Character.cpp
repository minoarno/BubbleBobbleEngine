#include "ColliderIncludes.h"
#include "Character.h"

Character::Character()
{
	if (m_pComponents.find("BoxCollider") == m_pComponents.end())
	{
		MidestinyEngine::BoxCollider* boxCollider = new MidestinyEngine::BoxCollider;

		m_pComponents.emplace(boxCollider->GetTypeName(), boxCollider);
	}
}

Character::~Character()
{
	MidestinyEngine::GameObject::~GameObject();
}

void Character::Start()
{
}

void Character::Update()
{
}

void Character::LateUpdate()
{
}

void Character::FixedUpdate()
{
}

void Character::Render() const
{
}

void Character::SetInput()
{
}
