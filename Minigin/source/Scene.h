#pragma once
#include "SceneManager.h"
#include "ColliderIncludes.h"

namespace dae
{
	class SceneObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(SceneObject* object);

		void Start();
		void Update();
		void LateUpdate();
		void FixedUpdate();
		void Render() const;

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

		b2World* GetWorld() { return m_pWorld; };
	private: 
		explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector <SceneObject*> m_Objects{};

		static unsigned int m_IdCounter;
		b2World* m_pWorld = nullptr;
	};
}
