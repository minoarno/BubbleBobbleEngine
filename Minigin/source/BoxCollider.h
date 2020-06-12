#pragma once
#include "BaseComponent.h"
#include "ColliderIncludes.h"
namespace dae
{
	class GameObject;
	class BoxCollider : public dae::BaseComponent
	{
	public:
		BoxCollider();
		~BoxCollider();

		virtual void Start() override;
		virtual void FixedUpdate() override;

		virtual void Render()const override;


	private:
		b2PolygonShape* m_pBodyshape = nullptr;
		b2FixtureDef m_FixtureDef;
		b2Fixture* m_pFixture = nullptr;
	};
}