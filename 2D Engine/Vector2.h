#pragma once

#include <glm/glm.hpp>

namespace TwoDE
{
	class Vector2
	{
		glm::vec2 self;

	public:
		Vector2(float x, float y);
		Vector2(const Vector2& other);
		float dot(Vector2& other);
		inline float getX() { return self.x; }
		inline float getY() { return self.y; }
		inline float setX(float x) { self.x = x; }
		inline float setY(float y) { self.y = y; }

		void operator+=(const Vector2& other);
		void operator*=(float scalar);
	};
}


