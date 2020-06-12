#pragma once
#include <deque>

class BaseBlock;
class Tilemap final
{
	Tilemap();
	~Tilemap();

	void LoadTileMapFromFile(const char* filename);
	void AddRow();
	void AddCollum();
private:
	std::deque<std::deque<BaseBlock*>> m_TilemapGrid;
};