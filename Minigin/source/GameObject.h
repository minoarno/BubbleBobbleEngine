#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <map>
#include <memory>
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
	protected:
		Transform* m_Transform;
		std::map<std::string, BaseComponent*> m_pComponents;
		std::shared_ptr<Texture2D> m_Texture{};
	};
}
