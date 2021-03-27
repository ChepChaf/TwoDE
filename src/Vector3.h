#pragma once

#include "Core.h"

#include "Vector2.h"

#include "spdlog/fmt/ostr.h"

namespace TwoDE
{
	class TWO_DLL Vector3
	{
	public:
		float x = 0, y = 0, z = 0;

		Vector3() {}
		Vector3(Vector2 other) : x(other.getX()), y(other.getY()) {}
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

		void operator+=(Vector3 other);
		void operator+=(Vector2 other);

		Vector3 operator+(Vector3 other);
		Vector3 operator+(float scalar);
		Vector3 operator-(Vector3 other);
		Vector3 operator-(float scalar);
		Vector3 operator+(Vector2 other);

		Vector3 operator*(float scalar);

		float dot(Vector3 other);
		Vector3 normalize();
		float magnitude();
	};
}
