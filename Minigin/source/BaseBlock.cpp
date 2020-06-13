#include "MiniginPCH.h"
#include "BaseBlock.h"
#include <iomanip>

namespace dae
{
	BaseBlock::BaseBlock()
		:GameObject{}
	{
	}

	BaseBlock::~BaseBlock()
	{
	}

	std::ostream& operator<<(std::ostream& out, const BaseBlock& block)
	{
		out << int(block.m_BlockType);
		return out;
	}
}
