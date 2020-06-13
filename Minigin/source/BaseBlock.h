#pragma once
namespace dae
{
	#include "GameObject.h"
	class BaseBlock : public dae::GameObject
	{
	public:
		enum class BlockType
		{
			Air = 0,
			BaseFill = 1
		};

		BaseBlock();
		virtual ~BaseBlock();

		void SetBlockType(BlockType blockType) { m_BlockType = blockType; }
		BlockType GetBlockType() { return m_BlockType; }
		friend std::ostream& operator<<(std::ostream& out, const BaseBlock& block);
	protected:
		BlockType m_BlockType = BlockType::Air;
	};

}