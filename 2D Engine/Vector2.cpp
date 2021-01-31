#include "Vector2.h"

namespace TwoDE
{
	Vector2::Vector2(float x, float y)
	{
		self = glm::vec2(x, y);
	}

	Vector2::Vector2(const Vector2& other)
	{
		self = other.self;
	}

	float Vector2::dot(Vector2& other)
	{
		return glm::dot(self, other.self);
	}

	void Vector2::operator+=(const Vector2& other)
	{
		self += other.self;
	}

	void Vector2::operator*=(float scalar)
	{
		self *= scalar;
	}
}