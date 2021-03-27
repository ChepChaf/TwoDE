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
	Transform::Transform(Vector3 position, float rotation, Vector2 scale) : m_Position(position), m_Rotation(rotation), m_Scale(scale)
	{
		recalculateMatrix();
	}

	void Transform::translate(Vector2 translation)
	{
		m_Position += translation;
		recalculateMatrix();
	}

	void Transform::translate(Vector3 translation)
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

	void Transform::setZ(int z)
	{
		m_Position.z = z;
		recalculateMatrix();
	}

	void Transform::setPosition(Vector3 pos)
	{
		m_Position = pos;
		recalculateMatrix();
	}
	Vector3 Transform::getPosition()
	{
		return m_Position;
	}

	Vector2 Transform::getPositionv2()
	{
		return Vector2{ m_Position.x, m_Position.y };
	}

	const Matrix4 Transform::getMatrix() const
	{
		return m_Matrix;
	}
}
