#pragma once

#include "Core.h"
#include "Vector2.h"
#include "Matrix4.h"

namespace TwoDE
{
	class TWO_DLL Transform
	{
		Vector2 m_Position;
		float m_Rotation;
		Vector2 m_Scale;

		Matrix4 m_Matrix;

		void recalculateMatrix();
	public:
		Transform(Vector2 position = { 0.0f, 0.0f }, float rotation = { 0.0f }, Vector2 scale = { 1.0f, 1.0f });

		void translate(Vector2 translation);
		void rotate(float rotation);
		void scale(Vector2 scale);

		void setPosition(Vector2 position);
		void setRotation(float rotation);
		void setScale(Vector2 scale);
		Vector2 setPosition();

		Vector2 getPosition();
		const Matrix4 getMatrix() const;
	};
}

