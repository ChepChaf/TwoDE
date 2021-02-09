#include "Transform.h"

namespace TwoDE
{
	Transform::Transform(Vector2 position, Vector2 rotation, Vector2 scale) : m_Position(position), m_Rotation(rotation), m_Scale(scale)
	{
	}

	void Transform::translate(Vector2 translation)
	{
		m_Position += translation;
	}

	void Transform::rotate(Vector2 rotation)
	{
		m_Rotation += rotation;
	}

	void Transform::scale(Vector2 scale)
	{
		m_Scale += scale;
	}

	void Transform::setPosition(Vector2 position)
	{
		m_Position = position;
	}

	void Transform::setRotation(Vector2 rotation)
	{
		m_Rotation = rotation;
	}

	void Transform::setScale(Vector2 scale)
	{
		m_Scale = scale;
	}

	Vector2 Transform::setPosition()
	{
		return m_Position;
	}
}
