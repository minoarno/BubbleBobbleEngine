#include "MiniginPCH.h"
#include "Tilemap.h"
#include "BaseBlock.h"
Tilemap::Tilemap()
{

}

Tilemap::~Tilemap()
{
	int amountRows = int(m_TilemapGrid.size());
	for (int i = 0; i < amountRows; i++)
	{
		int amountCollums = int(m_TilemapGrid[i].size());
		for (int k = 0; k < amountCollums; k++)
		{
			//delete m_TilemapGrid.at(i).at(k);
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

void Tilemap::LoadTileMapFromFile(const char* filename)
{
	ME_INFO(filename);
}

void Tilemap::AddRow()
{
	std::deque<BaseBlock*> baseBlocks;
	for(int i = 0; i < m_TilemapGrid[0].size(); i++)
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
