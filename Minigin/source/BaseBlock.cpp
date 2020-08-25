#include "MiniginPCH.h"
#include "BaseBlock.h"
#include <iomanip>

namespace MidestinyEngine
{
	BaseBlock::BaseBlock()
		:GameObject{}
	{
		SetTexture("Block.png");
		/*MidestinyEngine::BoxCollider* boxCollider = new MidestinyEngine::BoxCollider();
		boxCollider->SetSize(Core::g_BlockSize, Core::g_BlockSize);
		AddComponent(boxCollider);

		MidestinyEngine::RigidBody* rigid = new MidestinyEngine::RigidBody(false);
		AddComponent(rigid);*/

		Start();
	}

	void BaseBlock::Start()
	{
		/*if (m_BlockType == BlockType::Air)
		{
			if (m_pComponents.find("BoxCollider") != m_pComponents.end())
			{
				m_pComponents.erase("BoxCollider");
			}
		}
		else
		{
			if (m_pComponents.find("BoxCollider") != m_pComponents.end())
			{
				BoxCollider* boxCollider = new BoxCollider{};
				boxCollider->SetSize(Core::g_BlockSize, Core::g_BlockSize);
				boxCollider->SetGameObject(this);
				m_pComponents.emplace(boxCollider->GetTypeName(), boxCollider);
			}
			if (m_pComponents.find("RigidBody") != m_pComponents.end())
			{
				RigidBody* rigidBody = new RigidBody{true};
				rigidBody->SetGameObject(this);
				m_pComponents.emplace(rigidBody->GetTypeName(), rigidBody);
			}
		}*/
	}

	void BaseBlock::Update()
	{

	}

	void BaseBlock::LateUpdate()
	{
	}

	void BaseBlock::FixedUpdate()
	{
	}

	void BaseBlock::Render() const
	{
		if (m_BlockType != BlockType::Air)
		{
			const glm::vec3 pos = m_Transform->GetPosition();

			Renderer::GetInstance().RenderTexture(*m_pTexture, GetSourceRect(), GetBoundaries());
		}
	}

	Rectf BaseBlock::GetBoundaries() const
	{
		return Rectf{ m_Transform->GetPosition().x - Core::g_BlockSize / 2.f,m_Transform->GetPosition().y - Core::g_BlockSize / 2.f,Core::g_BlockSize,Core::g_BlockSize };
	}

	Rectf BaseBlock::GetSourceRect() const
	{
		return Rectf{ 0,0,float(m_pTexture->GetWidth() / 10),float(m_pTexture->GetHeight() / 10) };
	}

	void BaseBlock::CheckCollisionTopsideBlock(GameObject* gameObject)
	{
		HitInfo info{};
		Rectf actorShape{ gameObject->GetBoundaries() };

		Point2f leftMidPoint{ actorShape.x + actorShape.w * 0.5f , actorShape.y + actorShape.h / 2 };
		Point2f leftBotPoint{ actorShape.x + actorShape.w * 0.5f , actorShape.y };

		std::vector<Point2f> block{ Point2f{GetBoundaries().x,GetBoundaries().y + GetBoundaries().h}, Point2f{GetBoundaries().x + GetBoundaries().w,GetBoundaries().y + GetBoundaries().h} };

		if (Raycast(block, leftMidPoint, leftBotPoint, info))
		{
			gameObject->GetComponent<Transform>()->SetY(info.intersectPoint.y);
			gameObject->GetComponent<RigidBody>()->SetVelocityY(0);
		}
	}

	void BaseBlock::CheckCollisionBottomsideBlock(GameObject* gameObject)
	{
		HitInfo info{}, info2{};
		Rectf actorShape{ gameObject->GetBoundaries() };
		Point2f leftMidTop{ actorShape.x + actorShape.w * 0.1f,actorShape.y + actorShape.h };
		Point2f leftBotPoint{ actorShape.x + actorShape.w * 0.1f , actorShape.y + actorShape.h / 2 };
		Point2f rightMidTop{ actorShape.x + actorShape.w * 0.9f,actorShape.y + actorShape.h };
		Point2f rightBotPoint{ actorShape.x + actorShape.w * 0.9f , actorShape.y + actorShape.h / 2 };

		std::vector<Point2f> block{ Point2f{GetBoundaries().x,GetBoundaries().y}, Point2f{GetBoundaries().x + GetBoundaries().w,GetBoundaries().y} };

		bool raycastRight{ Raycast(block, leftMidTop, leftBotPoint, info) };
		bool raycastLeft{ Raycast(block, rightMidTop, rightBotPoint, info2) };

		if (raycastRight)
		{
			gameObject->GetComponent<Transform>()->SetY(info.intersectPoint.y - actorShape.h);
			gameObject->GetComponent<RigidBody>()->SetVelocityY(0);
		}
		else if (raycastLeft)
		{
			gameObject->GetComponent<Transform>()->SetY(info2.intersectPoint.y - actorShape.h);
			gameObject->GetComponent<RigidBody>()->SetVelocityY(0);
		}
	}

	void BaseBlock::CheckCollisionRightsideBlock(GameObject* gameObject)
	{
		HitInfo info{}, info2{};
		Rectf actorShape{ gameObject->GetBoundaries() };

		Point2f topLeftPoint{ actorShape.x,actorShape.y + actorShape.h * 0.9f };
		Point2f topMidPoint{ actorShape.x + actorShape.w / 2, actorShape.y + actorShape.h * 0.9f };
		Point2f botLeftPoint{ actorShape.x,actorShape.y + actorShape.h * 0.1f };
		Point2f botMidPoint{ actorShape.x + actorShape.w / 2, actorShape.y + actorShape.h * 0.1f };

		Point2f bottomRight{ GetBoundaries().x + GetBoundaries().w,GetBoundaries().y };
		Point2f topRight{ GetBoundaries().x + GetBoundaries().w,GetBoundaries().y + GetBoundaries().h };
		std::vector<Point2f> block{ bottomRight, topRight };

		bool topRaycast{ MidestinyEngine::Raycast(block, topLeftPoint, topMidPoint, info) };
		bool botRaycast{ MidestinyEngine::Raycast(block, botLeftPoint, botMidPoint, info2) };

		if (topRaycast)
		{
			gameObject->GetComponent<Transform>()->SetX(info.intersectPoint.x);
		}
		else if (botRaycast)
		{
			gameObject->GetComponent<Transform>()->SetX(info2.intersectPoint.x);
		}
	}

	void BaseBlock::CheckCollisionLeftsideBlock(GameObject* gameObject)
	{
		HitInfo info{}, info2{};
		const Rectf actorShape{ gameObject->GetBoundaries() };

		const Point2f botRightPoint{ actorShape.x + actorShape.w,actorShape.y + actorShape.h * 0.1f };
		const Point2f botMidPoint{ actorShape.x + actorShape.w / 2 , actorShape.y + actorShape.h * 0.1f };
		const Point2f topRightPoint{ actorShape.x + actorShape.w,actorShape.y + actorShape.h * 0.9f };
		const Point2f topMidPoint{ actorShape.x + actorShape.w / 2 , actorShape.y + actorShape.h * 0.9f };

		const Point2f bottomLeft{ GetBoundaries().x,GetBoundaries().y };
		const Point2f topLeft{ GetBoundaries().x,GetBoundaries().y + GetBoundaries().h };
		std::vector<Point2f> block{ bottomLeft ,topLeft };

		if (MidestinyEngine::Raycast(block, botRightPoint, botMidPoint, info))
		{
			gameObject->GetComponent<Transform>()->SetX(info.intersectPoint.x - actorShape.w);
		}
		else if (MidestinyEngine::Raycast(block, topRightPoint, topMidPoint, info2))
		{
			gameObject->GetComponent<Transform>()->SetX(info2.intersectPoint.x - actorShape.w);
		}
	}

	#ifdef _DEBUG
	void BaseBlock::UpdateBlockType()
	{
		m_BlockType = BlockType((1 +(int)m_BlockType) % 2);
		Start();
	}
	#endif
	std::ostream& operator<<(std::ostream& out, const BaseBlock& block)
	{
		out << int(block.m_BlockType);
		return out;
	}
}