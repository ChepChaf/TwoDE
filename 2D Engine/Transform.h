#pragma once

#include "Core.h"
#include "Vector2.h"

namespace TwoDE
{
	class TWO_DLL Transform
	{
		Vector2 m_Position;
		Vector2 m_Rotation;
		Vector2 m_Scale;
	public:
		Transform(Vector2 position = { 0.0f, 0.0f }, Vector2 rotation = { 0.0f, 0.0f }, Vector2 scale = { 1.0f, 1.0f });

		void translate(Vector2 translation);
		void rotate(Vector2 rotation);
		void scale(Vector2 scale);

		void setPosition(Vector2 position);
		void setRotation(Vector2 rotation);
		void setScale(Vector2 scale);
		Vector2 setPosition();
	};
}

