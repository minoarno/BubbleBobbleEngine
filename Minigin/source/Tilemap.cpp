#include "MiniginPCH.h"
#include "BaseBlock.h"
#include <regex>
#include <sstream>
#include "Tilemap.h"

namespace dae
{
	float Tilemap::m_BlockSize{ 20.f };

	Tilemap::Tilemap()
	{
		BaseBlock::SetBlockSize(m_BlockSize);
		for (int i = 0; i < 27; i++)
		{
			std::deque<BaseBlock*> blocks;
			for (int j = 0; j < 35; j++)
			{
				BaseBlock* block = new BaseBlock{};
				block->SetPosition((j + .5f) * m_BlockSize, (i + .5f) * m_BlockSize);
				blocks.push_back(block);
			}
			m_TilemapGrid.push_back(blocks);
		}
	}

	Tilemap::~Tilemap()
	{
		ClearGrid();
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

	void Tilemap::Start()
	{
		for (std::deque<BaseBlock*>& deque : m_TilemapGrid)
		{
			for (BaseBlock* block : deque)
			{
				if (block == nullptr) continue;
				block->Start();
			}
		}
	}

	void Tilemap::Update()
	{
		for (std::deque<BaseBlock*>& deque : m_TilemapGrid)
		{
			for (BaseBlock* block : deque)
			{
				if (block == nullptr) continue;
				block->Update();
			}
		}
	}

	void Tilemap::FixedUpdate()
	{
		for (std::deque<BaseBlock*>& deque : m_TilemapGrid)
		{
			for (BaseBlock* block : deque)
			{
				if (block == nullptr) continue;
				block->FixedUpdate();
			}
		}
	}

	void Tilemap::LateUpdate()
	{
		for (std::deque<BaseBlock*>& deque : m_TilemapGrid)
		{
			for (BaseBlock* block : deque)
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
		for (std::deque<BaseBlock*>& deque : m_TilemapGrid)
		{
			for (BaseBlock* block : deque)
			{
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
					m_TilemapGrid[h][w]->SetPosition((w + .5f) * m_BlockSize, (h + .5f)* m_BlockSize);
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