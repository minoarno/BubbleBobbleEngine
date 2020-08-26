#pragma once
#include <deque>
#include "SceneObject.h"

namespace MidestinyEngine
{
	class BaseBlock;
	class Tilemap : public SceneObject
	{
	public:
		Tilemap(const int defaultWidth, const int defaultHeight);
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
		friend std::ostream& operator<<(std::ostream& out, const Tilemap& tilemap);

		Rectf GetBoundaries()const;
	private:
		std::vector<std::vector<BaseBlock*>> m_TilemapGrid;

		Rectf m_LevelBoundaries;

		void ClearGrid();
	};
}