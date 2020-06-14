#include "MiniginPCH.h"
#include "BaseBlock.h"
#include <regex>
#include <sstream>
#include "Tilemap.h"

namespace MidestinyEngine
{
	Tilemap::Tilemap()
	{
		m_TilemapGrid.reserve(27);
		for (int i = 0; i < 27; i++)
		{
			std::vector<BaseBlock*> blocks;
			blocks.reserve(35);
			for (int j = 0; j < 35; j++)
			{
				BaseBlock* block = new BaseBlock{};
				block->SetPosition((j + .5f) * Core::g_BlockSize, (i + .5f) * Core::g_BlockSize);
				blocks.push_back(block);
			}
			m_TilemapGrid.push_back(blocks);
		}
		m_LevelBoundaries = Rectf{ 0,0,35 * Core::g_BlockSize,27 * Core::g_BlockSize };
	}

	Tilemap::~Tilemap()
	{
		ClearGrid();
	}

	void Tilemap::Start()
	{
		for (std::vector<BaseBlock*>& vector : m_TilemapGrid)
		{
			for (BaseBlock* block : vector)
			{
				if (block == nullptr) continue;
				block->Start();
			}
		}
	}

	void Tilemap::Update()
	{
		for (std::vector<BaseBlock*>& vector : m_TilemapGrid)
		{
			for (BaseBlock* block : vector)
			{
				if (block == nullptr) continue;
				block->Update();
			}
		}
	}

	void Tilemap::FixedUpdate()
	{
		for (std::vector<BaseBlock*>& vector : m_TilemapGrid)
		{
			for (BaseBlock* block : vector)
			{
				if (block == nullptr) continue;
				block->FixedUpdate();
			}
		}
	}

	void Tilemap::LateUpdate()
	{
		for (std::vector<BaseBlock*>& vector : m_TilemapGrid)
		{
			for (BaseBlock* block : vector)
			{
				if (block == nullptr) continue;
				block->LateUpdate();
			}
		}
	}

	void Tilemap::Render() const
	{
		for (int i = 0; i < m_TilemapGrid.size(); i++)
		{
			for (int x = 0; x < m_TilemapGrid.at(i).size(); x++)
			{
				if (m_TilemapGrid[i][x] == nullptr) continue;
				m_TilemapGrid[i][x]->Render();
			}
		}
	}

	#ifdef _DEBUG
	void Tilemap::TilemapBlockChanger(float x, float y)
	{
		for (std::vector<BaseBlock*>& vector : m_TilemapGrid)
		{
			for (BaseBlock* block : vector)
			{
				if (block == nullptr) continue;
				if (IsPointInRect(x, y, block->GetBoundaries()))
				{
					block->UpdateBlockType();
				}
			}
		}
	}
	#endif

	void Tilemap::ClearGrid()
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

	void Tilemap::LoadTileMapFromFile(int width, int height, const std::string& blockoutPart)
	{
		ClearGrid();
		m_TilemapGrid.reserve(height);
		for (int h = 0; h < height; h++)
		{
			std::vector<BaseBlock*> blocks;
			blocks.reserve(width);
			for (int w = 0; w < width; w++)
			{
				blocks.push_back(new BaseBlock{});
			}
			m_TilemapGrid.push_back(blocks);
		}

		std::stringstream blockout{ blockoutPart };
		size_t find{ 0 };
		char delimiter{ ' ' };
		for (int h = height - 1; h >= 0; h--)
		{
			for (int w = 0; w < width; w++)
			{
				size_t find1{ blockoutPart.find(delimiter,find) };
				int blockType = std::stoi(blockoutPart.substr(find, find1 - find));
				switch (blockType)
				{
			#ifndef _DEBUG
				case 0:
					delete m_TilemapGrid[h][w];
					m_TilemapGrid[h][w] = nullptr;
					break;
			#endif // !_DEBUG
				case -1:
					//Ghost
					break;
				default:
					m_TilemapGrid[h][w]->SetBlockType(BaseBlock::BlockType(blockType));
					m_TilemapGrid[h][w]->SetPosition((w + .5f) * Core::g_BlockSize, (h + .5f)* Core::g_BlockSize);
					break;
				}
				find = find1 + 1;
			}
		}
	}

	std::ostream& operator<<(std::ostream& out, const Tilemap& tilemap)
	{
		out << "Width " << int(tilemap.m_TilemapGrid[0].size()) << ' ';
		out << "Height " << int(tilemap.m_TilemapGrid.size()) << ' ';

		out << "Blockout ";
		for (int y = int(tilemap.m_TilemapGrid.size()) - 1; y >= 0; y--)
		{
			for (int x = 0; x < int(tilemap.m_TilemapGrid[y].size()); x++)
			{
				out << *tilemap.m_TilemapGrid[y][x] << ' ';
			}
		}
		return out;
	}
}