#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace TwoDE
{
	void Transform::recalculateMatrix()
	{
		// TODO: do this without glm
		m_Matrix = Matrix4(1.f);
		m_Matrix.translate(m_Position);
		m_Matrix.rotate(m_Rotation);
		m_Matrix.scale(m_Scale);
	}
	Transform::Transform(Vector2 position, float rotation, Vector2 scale) : m_Position(position), m_Rotation(rotation), m_Scale(scale)
	{
		recalculateMatrix();
	}

	void Transform::translate(Vector2 translation)
	{
		m_Position += translation;
		recalculateMatrix();
	}

	void Transform::rotate(float rotation)
	{
		m_Rotation += rotation;
		recalculateMatrix();
	}

	void Transform::scale(Vector2 scale)
	{
		m_Scale += scale;
		recalculateMatrix();
	}

	void Transform::setPosition(Vector2 position)
	{
		m_Position = position;
		recalculateMatrix();
	}

	void Transform::setRotation(float rotation)
	{
		m_Rotation = rotation;
		recalculateMatrix();
	}

	void Transform::setScale(Vector2 scale)
	{
		m_Scale = scale;
		recalculateMatrix();
	}

	Vector2 Transform::setPosition()
	{
		return m_Position;
	}
	const Matrix4 Transform::getMatrix() const
	{
		return m_Matrix;
	}
}
