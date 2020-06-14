#pragma once
#include "BaseComponent.h"

namespace MidestinyEngine
{
	class GameObject;
	class BoxCollider : public BaseComponent
	{
	public:
		BoxCollider();
		virtual ~BoxCollider() = default;

		virtual void Start() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void FixedUpdate() override;

		virtual void Render()const override;
		
		void SetSize(float width, float height);
	private:
		b2PolygonShape* m_pBodyshape = nullptr;
		b2FixtureDef m_FixtureDef;
		b2Fixture* m_pFixture = nullptr;
	};
}