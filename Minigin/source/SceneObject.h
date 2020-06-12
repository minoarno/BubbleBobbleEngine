#pragma once
namespace dae
{
	class Scene;
	class SceneObject
	{
	public:
		virtual void Start() = 0;
		virtual void Update() {};
		virtual void LateUpdate() {};
		virtual void FixedUpdate() {};
		virtual void Render() const {};

		SceneObject() = default;
		virtual ~SceneObject() = default;
		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;

		void SetScene(Scene* scene) { m_pScene = scene; }
		Scene* GetScene() { return m_pScene; }

		void SetName(const std::string& name) { m_Name = name; }
		std::string GetName() { return m_Name; }
	protected:
		Scene* m_pScene = nullptr;
		std::string m_Name;
	};
}