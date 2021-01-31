#pragma once

#include "Vector2.h"

namespace TwoDE
{
	class Transform
	{
		Vector2 m_Position;
		Vector2 m_Rotation;
		Vector2 m_Scale;
	public:
		Transform(Vector2 position = { 0.0f, 0.0f }, Vector2 rotation = { 0.0f, 0.0f }, Vector2 scale = { 1.0f, 1.0f });

		void Translate(Vector2 translation);
		void Rotate(Vector2 rotation);
		void Scale(Vector2 scale);
	};
}

