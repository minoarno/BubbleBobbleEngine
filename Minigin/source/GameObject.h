#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <map>
#include <memory>
#include "Structs.h"

namespace MidestinyEngine
{

	class Texture2D;
	class GameObject : public SceneObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		virtual void Start() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void FixedUpdate() override;
		virtual void Render() const override;

		virtual void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void AddComponent(BaseComponent* component);

		BaseComponent* GetComponent(const std::string& name);
		Transform* GetTransform()const { return m_Transform; }
		Rectf GetDestinationRectangle()const { return Rectf{ m_Transform->GetPosition().x, m_Transform->GetPosition().y,m_DestinationRectangle.w,m_DestinationRectangle.h };
		}
		void SetSize(float width, float height) { m_DestinationRectangle = Rectf{ m_Transform->GetPosition().x, m_Transform->GetPosition().y,width,height }; }
	protected:
		Rectf m_DestinationRectangle = Rectf{ 0,0,0,0 };
		Transform* m_Transform;
		std::map<std::string, BaseComponent*> m_pComponents;
		std::shared_ptr<Texture2D> m_pTexture{};
	};
}
