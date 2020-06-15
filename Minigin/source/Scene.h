#pragma once
#include "SceneManager.h"
#include "ColliderIncludes.h"

namespace MidestinyEngine
{
	class Tilemap;
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

		void LoadScene(int widthTilemap, int heightTilemap, const std::string& tileMapInfo);
		void LoadScene(int widthTilemap, int heightTilemap, const std::string& tileMapInfo, const std::string& gameObjectsInfo);
		void LoadObjects(const std::string& gameObjectsInfo);
		b2World* GetWorld() { return m_pWorld; };
		Tilemap* GetTilemap() { return m_pTilemap; }

		friend std::ostream& operator<<(std::ostream& out, const Scene& scene);
	private: 
		explicit Scene(const std::string& name);
		
		std::string m_Name;
		std::vector <SceneObject*> m_Objects{};

		static unsigned int m_IdCounter;
		b2World* m_pWorld = nullptr;
		Tilemap* m_pTilemap = nullptr;
	};
}
