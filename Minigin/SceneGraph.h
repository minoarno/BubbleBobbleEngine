#pragma once
#include <map>
#include <string>

class Scene;
class SceneGraph
{
public:
	~SceneGraph();
private:
	SceneGraph();
	static SceneGraph* m_pSceneGraph;

	std::map<std::string, int> m_IndexMapper;
	std::map<int, Scene*> m_Scenes;

	static int m_CurrentSceneIndex;
};

