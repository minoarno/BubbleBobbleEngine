#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
#pragma warning(pop)
#include "BaseComponent.h"
#include <string>
namespace MidestinyEngine
{
	class Transform final : public BaseComponent
	{
	public:
		Transform();
		Transform(const glm::vec3& pos);
		Transform(float x, float y, float z);
		~Transform() = default;

		virtual void Start() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void FixedUpdate() override;
		virtual void Render() const override;

		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);
		void SetPosition(const glm::vec3& pos);
		void SetX(float x) { m_Position.x = x; }
		void SetY(float y) { m_Position.y = y; }
		void SetZ(float z) { m_Position.z = z; }
		void SetPosThroughRigidBody(const glm::vec3& pos);
		void Translate(float x, float y, float z);
		void Translate(const glm::vec3& pos);

		void SetLevelBoundariesClamp(bool value) { m_LevelBoundariesClamp = value; };
	private:
		glm::vec3 m_Position;
		bool m_LevelBoundariesClamp = true;

		void ClampLevelBoundaries();
	};
}