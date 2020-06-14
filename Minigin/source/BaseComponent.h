#pragma once
#include <string>
namespace MidestinyEngine
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent() = default;
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render()const = 0;
		std::string GetTypeName();
		void SetGameObject(GameObject* owner);
	protected:
		GameObject* m_pOwnerGameObject = nullptr;
		std::string m_TypeName;
	};
}