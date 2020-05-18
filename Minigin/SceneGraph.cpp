#include "MiniginPCH.h"
#include "SceneGraph.h"

SceneGraph::SceneGraph()
{
	if (m_pSceneGraph == nullptr)
	{
		m_pSceneGraph = this;
	}
	else
	{
		SceneGraph::~SceneGraph();
	}
}

SceneGraph::~SceneGraph()
{
	//Delete all the scenes
	m_IndexMapper.clear();
	m_Scenes.clear();
}
