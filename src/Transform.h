#pragma once

#include "Core.h"

#include <glm/glm.hpp>

namespace TwoDE
{
	class TWO_DLL Transform
	{
		void recalculateMatrix();
	public:
		glm::mat4 matrix;
		glm::vec3 m_Position;
		glm::vec3 m_Scale;
		float m_Rotation;

		Transform(glm::vec3 position = { 0.0f, 0.0f, 0.0f }, float rotation = { 0.0f }, glm::vec3 scale = { 10.0f, 10.0f, 0.0f });

		void translate(glm::vec2 translation);
		void translate(glm::vec3 translation);

		void rotate(float rotation);
		void scale(glm::vec3 scale);

		void setRotation(float rotation);
		void setScale(glm::vec3 scale);
		void setZ(int z);
		void setPosition(glm::vec3 pos);

		glm::vec3 getPosition();
		glm::vec2 getPositionv2();

		const glm::mat4 getMatrix() const;
	};
}

