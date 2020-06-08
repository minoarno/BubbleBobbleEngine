#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
#pragma warning(pop)
#include "BaseComponent.h"

namespace dae
{
	class Transform final //: public BaseComponent
	{
	public:
		Transform();
		~Transform();

		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);
		void SetPosition(const glm::vec3& pos);
		void Translate(float x, float y, float z);
		void Translate(const glm::vec3& pos);
	private:
		glm::vec3 m_Position;
	};
}