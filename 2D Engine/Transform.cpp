#include "Transform.h"

namespace TwoDE
{
	Transform::Transform(Vector2 position, Vector2 rotation, Vector2 scale) : m_Position(position), m_Rotation(rotation), m_Scale(scale)
	{
	}

	void Transform::Translate(Vector2 translation)
	{
		m_Position += translation;
	}

	void Transform::Rotate(Vector2 rotation)
	{
		m_Rotation += rotation;
	}

	void Transform::Scale(Vector2 scale)
	{
		m_Scale += scale;
	}
}
