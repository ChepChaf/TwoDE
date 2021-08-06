#pragma once

#include "Core.h"

namespace TwoDE
{
	class TWO_DLL Vector2
	{
		float x, y;
	public:
		Vector2() : x(0), y(0) {}
		Vector2(float x, float y);
		Vector2(const Vector2& other);
		float dot(const Vector2& other);
		inline float getX() { return x; }
		inline float getY() { return y; }
		inline void setX(float x) { this->x = x; }
		inline void setY(float y) { this->y = y; }
		
		Vector2 normalized();

		float magnitude();
		float angle(Vector2& other);
		
		void operator+=(const Vector2& other);
		void operator+=(float scalar);
		Vector2 operator+(float scalar);
		Vector2 operator+(Vector2 other);
		Vector2 operator-(Vector2 other);
		void operator*=(float scalar);
	};

	inline Vector2 operator*(Vector2 vec, float scalar)
	{
		return Vector2{ vec.getX() * scalar, vec.getY() * scalar };
	}
}


