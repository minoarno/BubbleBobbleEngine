#include "MiniginPCH.h"
#include "BaseBlock.h"
#include <regex>
#include <sstream>
#include "Tilemap.h"

namespace dae
{
	Tilemap::Tilemap()
	{
		for (int i = 0; i < 27; i++)
		{
			std::deque<BaseBlock*> blocks;
			for (int j = 0; j < 35; j++)
			{
				BaseBlock* block = new BaseBlock{};
				blocks.push_back(block);
			}
			m_TilemapGrid.push_back(blocks);
		}
	}

	Tilemap::~Tilemap()
	{
		int amountRows = int(m_TilemapGrid.size());
		for (int i = 0; i < amountRows; i++)
		{
			int amountCollums = int(m_TilemapGrid[i].size());
			for (int k = 0; k < amountCollums; k++)
			{
				delete m_TilemapGrid[i][k];
				m_TilemapGrid[i][k] = nullptr;
			}
		}
		for (int i = 0; i < amountRows; i++)
		{
			m_TilemapGrid[i].clear();
		}
		m_TilemapGrid.clear();
	}

	void Tilemap::AddRow()
	{
		std::deque<BaseBlock*> baseBlocks;
		for (int i = 0; i < m_TilemapGrid[0].size(); i++)
		{
			baseBlocks.push_back(nullptr);
		}
		m_TilemapGrid.push_back(baseBlocks);
	}

	void Tilemap::AddCollum()
	{
		for (int i = 0; i < m_TilemapGrid.size(); i++)
		{
			m_TilemapGrid.at(i).push_back(nullptr);
		}
	}

	void Tilemap::LoadTileMapFromFile(int width, int height, const std::string& blockoutPart)
	{
		for (int h = 0; h < height; h++)
		{
			std::deque<BaseBlock*> blocks;
			for (int w = 0; w < width; w++)
			{
				blocks.push_back(new BaseBlock{});
			}
			m_TilemapGrid.push_back(blocks);
		}

		std::stringstream blockout{ blockoutPart };
		size_t find{ 0 };
		char delimiter{ ' ' };
		for (int h = 0; h < height; h++)
		{
			for (int w = 0; w < width; w++)
			{
				size_t find1{ blockoutPart.find(delimiter,find) };
				int blockType = std::stoi(blockoutPart.substr(find, find1 - find));
				switch (blockType)
				{
				case 0:
					delete m_TilemapGrid[h][w];
					m_TilemapGrid[h][w] = nullptr;
					break;
				default:
					m_TilemapGrid[h][w]->SetBlockType(BaseBlock::BlockType(blockType));
					m_TilemapGrid[h][w]->SetPosition(w * m_BlockSize, h * m_BlockSize);
					break;
				}
				find = find1 + 1;
			}
		}
	}

	std::ostream& operator<<(std::ostream& out, const Tilemap& tilemap)
	{
		out << "Width " << int(tilemap.m_TilemapGrid[0].size());
		out << " " << "Height " << int(tilemap.m_TilemapGrid.size()) << "\n";

		out << "Blockout\"" << std::endl;
		for (int y = int(tilemap.m_TilemapGrid.size()) - 1; y >= 0; y--)
		{
			for (int x = 0; x < int(tilemap.m_TilemapGrid[y].size()); x++)
			{
				out << *tilemap.m_TilemapGrid[y][x] << ' ';
			}
			out << std::endl;
		}
		out << "\"/>\n\n";
		return out;
	}
}