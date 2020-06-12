#include "MiniginPCH.h"
#include "ColliderIncludes.h"

using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene() = default;

void Scene::Add(SceneObject* object)
{
	object->SetScene(this);
	m_Objects.push_back(object);
}

void dae::Scene::Start()
{
	m_pWorld = new b2World(b2Vec2{ 0,9.81f });

	for (SceneObject* object : m_Objects)
	{
		object->Start();
	}
}

void Scene::Update()
{
	for (SceneObject* object : m_Objects)
	{
		object->Update();
	}
}

void Scene::LateUpdate()
{
	for (SceneObject* object : m_Objects)
	{
		object->LateUpdate();
	}
}

void dae::Scene::FixedUpdate()
{
	m_pWorld->Step(.5f,3,8);
	for (SceneObject* object : m_Objects)
	{
		
		object->FixedUpdate();
	}
}

void Scene::Render() const
{
	for (SceneObject* object : m_Objects)
	{
		object->Render();
	}
}

