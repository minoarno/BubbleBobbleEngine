#pragma once
#include <deque>
namespace dae
{
	class BaseBlock;
	class Tilemap
	{
	public:
		Tilemap();
		~Tilemap();

		void LoadTileMapFromFile(int width, int height, const std::string& blockoutPart);
		void AddRow();
		void AddCollum();

		friend std::ostream& operator<<(std::ostream& out, const Tilemap& tilemap);
	private:
		std::deque<std::deque<BaseBlock*>> m_TilemapGrid;
		const float m_BlockSize = 20.f;
	};
}