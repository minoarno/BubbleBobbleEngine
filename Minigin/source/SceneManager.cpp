#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void MidestinyEngine::SceneManager::Update()
{
	if (m_Scenes.find(m_CurrentSceneIndex) != m_Scenes.end())
	{
		m_Scenes[m_CurrentSceneIndex]->Update();
	}
	else
	{
		ME_CORE_ERROR("Scene with index {0} doesn't exist",m_CurrentSceneIndex);
	}
}

void MidestinyEngine::SceneManager::LateUpdate()
{
	if (m_Scenes.find(m_CurrentSceneIndex) != m_Scenes.end())
	{
		m_Scenes[m_CurrentSceneIndex]->LateUpdate();
	}
	else
	{
		ME_CORE_ERROR("Scene with index {0} doesn't exist", m_CurrentSceneIndex);
	}
}

void MidestinyEngine::SceneManager::FixedUpdate()
{
	if (m_Scenes.find(m_CurrentSceneIndex) != m_Scenes.end())
	{
		m_Scenes[m_CurrentSceneIndex]->FixedUpdate();
	}
	else
	{
		ME_CORE_ERROR("Scene with index {0} doesn't exist", m_CurrentSceneIndex);
	}
}

void MidestinyEngine::SceneManager::Render()
{
	if (m_Scenes.find(m_CurrentSceneIndex) != m_Scenes.end())
	{
		m_Scenes[m_CurrentSceneIndex]->Render();
	}
	else
	{
		ME_CORE_ERROR("Scene with index {0} doesn't exist", m_CurrentSceneIndex);
	}
}

void MidestinyEngine::SceneManager::SaveScenesToFile(const std::string& filename)
{
	ME_CORE_INFO("Creating file {0} to save scenes",filename);

	std::fstream out{ filename };
	CheckStream(out);
	for (std::pair<int, Scene*> scene : m_Scenes)
	{
		out << *scene.second << '\n';
	}
	out.close();
}

void MidestinyEngine::SceneManager::LoadScenesFromFile(const std::string& filename)
{
	std::ifstream in{ filename };
	std::string temp{};
	while (!in.eof())
	{
		std::getline(in, temp, '>');
		if (temp != "\n")
		{
			std::regex levelRegex{ "<Scene (\\w+) Width (\\d+) Height (\\d+) Blockout (.+) GameObjects (.*)" };

			std::smatch matches;
			if (std::regex_search(temp, matches, levelRegex))
			{
				ME_CORE_INFO(matches[1].str());
				Scene& scene = CreateScene(matches[1].str());
				scene.LoadScene(std::stoi(matches[2].str()), std::stoi(matches[3].str()), matches[4].str(), matches[5].str());
			}
			else
			{
				ME_CORE_ERROR("File {0} doesn't match: {1} is not compatible with", filename, temp);
			}
		}
	}
	in.close();
}

MidestinyEngine::Scene* MidestinyEngine::SceneManager::GetActiveScene()
{
	if (m_Scenes.find(m_CurrentSceneIndex) == m_Scenes.end())
	{
		ME_CORE_ERROR("Active scene can't be found", m_CurrentSceneIndex);
		return nullptr;
	}
	return m_Scenes[m_CurrentSceneIndex];
}

void MidestinyEngine::SceneManager::NextScene(int index)
{
	if (m_Scenes.find(index) != m_Scenes.end())
	{
		m_CurrentSceneIndex = index;
	}
}

void MidestinyEngine::SceneManager::NextScene(const std::string& sceneName)
{
	if (m_NameToIndexList.find(sceneName) != m_NameToIndexList.end())
	{
		if (m_Scenes.find(m_NameToIndexList[sceneName]) != m_Scenes.end())
		{
			m_CurrentSceneIndex = m_NameToIndexList[sceneName];
		}
	}
	else
	{
		ME_CORE_ERROR("Can't load in scene with name {0}", sceneName);
	}
}

MidestinyEngine::SceneManager::~SceneManager()
{
	CleanUp();
}

void MidestinyEngine::SceneManager::CleanUp()
{
	if (m_Scenes.size() != 0)
	{
		for (std::pair<int, Scene*> scene : m_Scenes)
		{
			delete scene.second;
			scene.second = nullptr;
		}
		m_Scenes.clear();
		m_NameToIndexList.clear();
	}
}

MidestinyEngine::Scene& MidestinyEngine::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = new Scene(name);
	int index = int(m_Scenes.size());
	m_Scenes.emplace(index,scene);
	m_NameToIndexList.emplace(name, index);
	return *scene;
}