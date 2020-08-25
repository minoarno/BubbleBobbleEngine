#pragma once
namespace MidestinyEngine
{
	class Scene;
	class SceneObject
	{
	public:
		SceneObject() = default;
		virtual ~SceneObject() = default;
		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;

		virtual void Start() = 0;
		virtual void Update() {};
		virtual void LateUpdate() {};
		virtual void FixedUpdate() {};
		virtual void Render() const {};

		void SetScene(Scene* scene) { m_pScene = scene; }
		Scene* GetScene() { return m_pScene; }

		void SetName(const std::string& name) { m_Name = name; }
		std::string GetName() { return m_Name; }

		void SetTag(const std::string& tag) { m_Tag = tag; }
		std::string GetTag() { return m_Tag; }
	protected:
		Scene* m_pScene = nullptr;
		std::string m_Name = "";
		std::string m_Tag = "";
	};
}