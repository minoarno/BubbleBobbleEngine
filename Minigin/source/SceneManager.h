#pragma once
#include "Singleton.h"
#include <map>

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);
		void Update();
		void LateUpdate();
		void Render();
		void SaveScenesToFile(const std::string& filename);
		void LoadScenesFromFile(const std::string& filename);
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;

		std::map<int, std::shared_ptr<Scene>> m_Scenes;
		std::map<std::string, int> m_NameToIndexList;
		int m_CurrentSceneIndex = 0;
	};
}