#pragma once
#include <deque>
#include "SceneObject.h"

namespace dae
{
	class BaseBlock;
	class Tilemap : public SceneObject
	{
	public:
		Tilemap();
		~Tilemap();

		void LoadTileMapFromFile(int width, int height, const std::string& blockoutPart);

		virtual void Start() override;
		virtual void Update() override;
		virtual void FixedUpdate() override;
		virtual void LateUpdate() override;
		virtual void Render()const override;
	#ifdef _DEBUG
		virtual void TilemapBlockChanger(float x, float y);
	#endif
		static float GetBlockSize() { return m_BlockSize; }

		friend std::ostream& operator<<(std::ostream& out, const Tilemap& tilemap);

		Rectf GetLevelBoundaries()const { return m_LevelBoundaries; }
	private:
		std::vector<std::vector<BaseBlock*>> m_TilemapGrid;
		static float m_BlockSize;

		Rectf m_LevelBoundaries;

		void ClearGrid();
	};
}