#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace TwoDE
{
	void Transform::recalculateMatrix()
	{
		// TODO: do this without glm
		matrix = glm::mat4(1.f);
		matrix = glm::translate(matrix, m_Position);
		matrix = glm::rotate(matrix, m_Rotation, glm::vec3{0, 0, 1});
		matrix = glm::scale(matrix, m_Scale);
	}
	Transform::Transform(glm::vec3 position, float rotation, glm::vec3 scale) : m_Position(position), m_Rotation(rotation), m_Scale(scale)
	{
		recalculateMatrix();
	}

	void Transform::translate(glm::vec2 translation)
	{
		m_Position += glm::vec3{translation, 0.0f};
		recalculateMatrix();
	}

	void Transform::translate(glm::vec3 translation)
	{
		m_Position += translation;
		recalculateMatrix();
	}

	void Transform::rotate(float rotation)
	{
		m_Rotation += rotation;
		recalculateMatrix();
	}

	void Transform::scale(glm::vec3 scale)
	{
		m_Scale += scale;
		recalculateMatrix();
	}

	void Transform::setRotation(float rotation)
	{
		m_Rotation = rotation;
		recalculateMatrix();
	}

	void Transform::setScale(glm::vec3 scale)
	{
		m_Scale = scale;
		recalculateMatrix();
	}

	void Transform::setZ(int z)
	{
		m_Position.z = z;
		recalculateMatrix();
	}

	void Transform::setPosition(glm::vec3 pos)
	{
		m_Position = pos;
		recalculateMatrix();
	}
	glm::vec3 Transform::getPosition()
	{
		return m_Position;
	}

	glm::vec2 Transform::getPositionv2()
	{
		return glm::vec2{ m_Position.x, m_Position.y };
	}

	const glm::mat4 Transform::getMatrix() const
	{
		return matrix;
	}
}
