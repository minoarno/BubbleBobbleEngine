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

		virtual void Start() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void FixedUpdate() override;
		virtual void Render() const override;

		void SetBlockType(BlockType blockType) { m_BlockType = blockType; }
		BlockType GetBlockType() { return m_BlockType; }
		static void SetBlockSize(float size) { m_BlockSize = size; }
		friend std::ostream& operator<<(std::ostream& out, const BaseBlock& block);

		void UpdateBlockType();
		Rectf GetBoundaries()const;
		Rectf GetSourceRect()const;
	protected:
		BlockType m_BlockType = BlockType::BaseFill;
		static float m_BlockSize;
	};
}