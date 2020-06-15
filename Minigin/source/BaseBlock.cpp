#include "MiniginPCH.h"
#include "BaseBlock.h"
#include <iomanip>

namespace MidestinyEngine
{
	BaseBlock::BaseBlock()
		:GameObject{}
	{
		SetTexture("LevelBlocks.png");
		/*MidestinyEngine::BoxCollider* boxCollider = new MidestinyEngine::BoxCollider();
		boxCollider->SetSize(Core::g_BlockSize, Core::g_BlockSize);
		AddComponent(boxCollider);

		MidestinyEngine::RigidBody* rigid = new MidestinyEngine::RigidBody(false);
		AddComponent(rigid);*/

		Start();
	}

	void BaseBlock::Start()
	{
		/*if (m_BlockType == BlockType::Air)
		{
			if (m_pComponents.find("BoxCollider") != m_pComponents.end())
			{
				m_pComponents.erase("BoxCollider");
			}
		}
		else
		{
			if (m_pComponents.find("BoxCollider") != m_pComponents.end())
			{
				BoxCollider* boxCollider = new BoxCollider{};
				boxCollider->SetSize(Core::g_BlockSize, Core::g_BlockSize);
				boxCollider->SetGameObject(this);
				m_pComponents.emplace(boxCollider->GetTypeName(), boxCollider);
			}
			if (m_pComponents.find("RigidBody") != m_pComponents.end())
			{
				RigidBody* rigidBody = new RigidBody{true};
				rigidBody->SetGameObject(this);
				m_pComponents.emplace(rigidBody->GetTypeName(), rigidBody);
			}
		}*/
	}

	void BaseBlock::Update()
	{

	}

	void BaseBlock::LateUpdate()
	{
	}

	void BaseBlock::FixedUpdate()
	{
	}

	void BaseBlock::Render() const
	{
		if (m_BlockType != BlockType::Air)
		{
			const glm::vec3 pos = m_Transform->GetPosition();

			Renderer::GetInstance().RenderTexture(*m_pTexture, GetSourceRect(), GetBoundaries());
		}
	}

	Rectf BaseBlock::GetBoundaries() const
	{
		return Rectf{ m_Transform->GetPosition().x - Core::g_BlockSize / 2.f,m_Transform->GetPosition().y - Core::g_BlockSize / 2.f,Core::g_BlockSize,Core::g_BlockSize };
	}

	Rectf BaseBlock::GetSourceRect() const
	{
		return Rectf{ 0,0,float(m_pTexture->GetWidth() / 10),float(m_pTexture->GetHeight() / 10) };
	}

	#ifdef _DEBUG
	void BaseBlock::UpdateBlockType()
	{
		m_BlockType = BlockType((1 +(int)m_BlockType) % 2);
		Start();
	}
	#endif
	std::ostream& operator<<(std::ostream& out, const BaseBlock& block)
	{
		out << int(block.m_BlockType);
		return out;
	}
}