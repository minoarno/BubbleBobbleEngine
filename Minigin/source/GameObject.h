#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <map>
#include <memory>
namespace dae
{
	class Texture2D;
	class GameObject : public SceneObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		void Awake() override;
		void Update() override;
		void LateUpdate() override;
		void FixedUpdate() override;
		void Render() const override;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void AddComponent(BaseComponent* component);

	private:
		Transform* m_Transform;
		std::map<std::string, BaseComponent*> m_Components;
		std::shared_ptr<Texture2D> m_Texture{};
	};
}
