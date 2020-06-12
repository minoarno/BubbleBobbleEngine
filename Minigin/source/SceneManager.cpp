#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Update()
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

void dae::SceneManager::LateUpdate()
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

void dae::SceneManager::FixedUpdate()
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

void dae::SceneManager::Render()
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

void dae::SceneManager::SaveScenesToFile(const std::string& filename)
{
	ME_CORE_INFO(filename);
}

void dae::SceneManager::LoadScenesFromFile(const std::string& filename)
{
	ME_CORE_INFO(filename);
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	int index = int(m_Scenes.size());
	m_Scenes.emplace(index,scene);
	m_NameToIndexList.emplace(name, index);
	return *scene;
}