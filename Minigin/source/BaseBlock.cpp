#include "MiniginPCH.h"
#include "BaseBlock.h"
#include <iomanip>

namespace dae
{
	float BaseBlock::m_BlockSize = 0;

	BaseBlock::BaseBlock()
		:GameObject{}
	{
		SetTexture("LevelBlocks.png");
	}

	BaseBlock::~BaseBlock()
	{
	}

	void BaseBlock::Start()
	{
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

			Renderer::GetInstance().RenderTexture(*m_Texture, GetSourceRect(), GetBoundaries());
		}
		//else
		//{
		//	Rectf source{ float(m_Texture->GetWidth() / 10),0,float(m_Texture->GetWidth() / 10),float(m_Texture->GetHeight() / 10) };
		//	Renderer::GetInstance().RenderTexture(*m_Texture, source, GetBoundaries());
		//}

		//m_Texture
		//SetColor(Color4f{ 1.f,0.f,0.f,1.f });
		//DrawRect(Rectf{ m_Transform->GetPosition().x - m_BlockSize / 2.f,m_Transform->GetPosition().y - m_BlockSize / 2.f,m_BlockSize,m_BlockSize });
		//ME_INFO("{0} {1} {2} {3}", m_Transform->GetPosition().x - m_BlockSize / 2.f, m_Transform->GetPosition().y - m_BlockSize / 2.f, m_BlockSize, m_BlockSize);
	}

	Rectf BaseBlock::GetBoundaries() const
	{
		return Rectf{ m_Transform->GetPosition().x - m_BlockSize / 2.f,m_Transform->GetPosition().y - m_BlockSize / 2.f,m_BlockSize,m_BlockSize };
	}

	Rectf BaseBlock::GetSourceRect() const
	{
		return Rectf{ 0,0,float(m_Texture->GetWidth() / 10),float(m_Texture->GetHeight() / 10) };
	}

	#ifdef _DEBUG
	void BaseBlock::UpdateBlockType()
	{
		m_BlockType = BlockType((1 +(int)m_BlockType) % 2);
	}
	#endif
	std::ostream& operator<<(std::ostream& out, const BaseBlock& block)
	{
		out << int(block.m_BlockType);
		return out;
	}
}