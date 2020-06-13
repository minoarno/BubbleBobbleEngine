#include "MiniginPCH.h"
#include "ColliderIncludes.h"
#include "Tilemap.h"

namespace dae
{
	unsigned int Scene::m_IdCounter = 0;

	void Scene::LoadScene(int widthTilemap, int heightTilemap, const std::string& tileMapInfo, const std::string& gameObjectsInfo)
	{
		m_pTilemap = new Tilemap{};
		m_pTilemap->LoadTileMapFromFile(widthTilemap, heightTilemap, tileMapInfo);
		LoadObjects(gameObjectsInfo);
	}

	void Scene::LoadObjects(const std::string& gameObjectsInfo)
	{
		ME_INFO(gameObjectsInfo);
	}

	Scene::Scene(const std::string& name) : m_Name(name) {}

	Scene::~Scene()
	{
		delete m_pTilemap;
		m_pTilemap = nullptr;

		for (SceneObject* object : m_Objects)
		{
			delete object;
			object = nullptr;
		}
		m_Objects.clear();
	}

	void Scene::Add(SceneObject * object)
	{
		object->SetScene(this);
		m_Objects.push_back(object);
	}

	void dae::Scene::Start()
	{
		m_pWorld = new b2World{ b2Vec2{0,9.81f} };

		for (SceneObject* object : m_Objects)
		{
			object->Start();
		}
		if (m_pTilemap != nullptr)
		{
			m_pTilemap->Start();
		}
		else
		{
			ME_CORE_ERROR("Tilemap isn't loaded in");
			m_pTilemap = new Tilemap{};
		}
	}

	void Scene::Update()
	{
		for (SceneObject* object : m_Objects)
		{
			object->Update();
		}
		if (m_pTilemap != nullptr)
		{
			m_pTilemap->Update();
		}
		else
		{
			ME_CORE_ERROR("Tilemap isn't loaded in");
			m_pTilemap = new Tilemap{};
		}
	}

	void Scene::LateUpdate()
	{
		for (SceneObject* object : m_Objects)
		{
			object->LateUpdate();
		}
		if (m_pTilemap != nullptr)
		{
			m_pTilemap->LateUpdate();
		}
		else
		{
			ME_CORE_ERROR("Tilemap isn't loaded in");
			m_pTilemap = new Tilemap{};
		}
	}

	void dae::Scene::FixedUpdate()
	{
		//m_pWorld->Step(.5f,3,8);
		for (SceneObject* object : m_Objects)
		{

			object->FixedUpdate();
		}
		if (m_pTilemap != nullptr)
		{
			m_pTilemap->FixedUpdate();
		}
		else
		{
			ME_CORE_ERROR("Tilemap isn't loaded in");
			m_pTilemap = new Tilemap{};
		}
	}

	void Scene::Render() const
	{
		for (SceneObject* object : m_Objects)
		{
			object->Render();
		}
		if (m_pTilemap != nullptr)
		{
			m_pTilemap->Render();
		}
		else
		{
			ME_CORE_ERROR("Tilemap isn't loaded in");
		}
	}
	std::ostream& operator<<(std::ostream& out, const Scene& scene)
	{
		out << "<Scene " << scene.m_Name << " " << *scene.m_pTilemap << " GameObjects >";
		return out;
	}
}


