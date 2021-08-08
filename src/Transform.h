#pragma once

#include "Core.h"
#include "Vector2.h"
#include "Vector3.h"

#include "Matrix4.h"

namespace TwoDE
{
	class TWO_DLL Transform
	{
		void recalculateMatrix();
	public:
		Matrix4 matrix;
		Vector3 m_Position;
		Vector2 m_Scale;
		float m_Rotation;

		Transform(Vector3 position = { 0.0f, 0.0f, 0.0f }, float rotation = { 0.0f }, Vector2 scale = { 10.0f, 10.0f });

		void translate(Vector2 translation);
		void translate(Vector3 translation);

		void rotate(float rotation);
		void scale(Vector2 scale);

		void setRotation(float rotation);
		void setScale(Vector2 scale);
		void setZ(int z);
		void setPosition(Vector3 pos);

		Vector3 getPosition();
		Vector2 getPositionv2();

		const Matrix4 getMatrix() const;
	};
}

