#pragma once

#include <glm/glm.hpp>

#include "Core.h"

namespace TwoDE
{
	class TWO_DLL Vector2
	{
		float x, y;
	public:
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
		void operator*=(float scalar);
	};
}


