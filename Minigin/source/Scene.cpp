#include "MiniginPCH.h"
#include "ColliderIncludes.h"
#include "Tilemap.h"
#include "GameTime.h"

namespace MidestinyEngine
{
	unsigned int Scene::m_IdCounter = 0;

	void Scene::LoadScene(int widthTilemap, int heightTilemap, const std::string& tileMapInfo)
	{
		m_pTilemap = new Tilemap{};
		m_pTilemap->LoadTileMapFromFile(widthTilemap, heightTilemap, tileMapInfo);
	}

	void MidestinyEngine::Scene::LoadScene(int widthTilemap, int heightTilemap, const std::string& tileMapInfo, const std::string& gameObjectsInfo)
	{
		m_pTilemap = new Tilemap{};
		m_pTilemap->LoadTileMapFromFile(widthTilemap, heightTilemap, tileMapInfo);
		ME_INFO(gameObjectsInfo);
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

		delete m_pWorld;
		m_pWorld = nullptr;
	}

	void Scene::Add(SceneObject * object)
	{
		object->SetScene(this);
		m_Objects.push_back(object);
	}

	void MidestinyEngine::Scene::Start()
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
		float sec = GameTime::GetInstance().GetElapsedSeconds();
		m_pWorld->Step(sec, 8, 3);
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

	void MidestinyEngine::Scene::FixedUpdate()
	{

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

		if (m_pTilemap != nullptr)
		{
			m_pTilemap->Render();
		}
		else
		{
			ME_CORE_ERROR("Tilemap isn't loaded in");
		}
		for (SceneObject* object : m_Objects)
		{
			object->Render();
		}
	//#ifdef _DEBUG
	//	m_pWorld->DebugDraw();
	//#endif // _DEBUG
	}

	std::ostream& operator<<(std::ostream& out, const Scene& scene)
	{
		out << "<Scene " << scene.m_Name << " " << *scene.m_pTilemap << " GameObjects >";
		return out;
	}
}


