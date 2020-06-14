#pragma once
#include "Singleton.h"
#include <map>

namespace MidestinyEngine
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		~SceneManager();
		Scene& CreateScene(const std::string& name);
		void Update();
		void LateUpdate();
		void FixedUpdate();
		void Render();
		void SaveScenesToFile(const std::string& filename);
		void LoadScenesFromFile(const std::string& filename);
		Scene* GetActiveScene();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;

		std::map<int, Scene*> m_Scenes;
		std::map<std::string, int> m_NameToIndexList;
		int m_CurrentSceneIndex = 0;
	};
}