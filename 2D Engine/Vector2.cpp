#include "Vector2.h"

#include <cmath>

namespace TwoDE
{
	Vector2::Vector2(float x, float y) : x(x), y(y)
	{
	}

	Vector2::Vector2(const Vector2& other)
	{
		x = other.x;
		y = other.y;
	}

	float Vector2::magnitude()
	{
		return std::sqrt((x * x) + (y * y));
	}

	float Vector2::dot(const Vector2& other)
	{
		return x * other.x + y * other.y;
	}

	Vector2 Vector2::normalized()
	{
		float thisMagnitude = magnitude();
		return Vector2(x / thisMagnitude, y / thisMagnitude);
	}

	float Vector2::angle(Vector2& other)
	{
		Vector2 thisNormalized = normalized();
		return std::acos(thisNormalized.dot(other.normalized())) * (180/3.14159f);
	}

	void Vector2::operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
	}

	void Vector2::operator+=(float scalar)
	{
		x += scalar;
		y += scalar;
	}

	Vector2 Vector2::operator+(float scalar)
	{
		return Vector2(x + scalar, y + scalar);
	}

	Vector2 Vector2::operator+(Vector2 other)
	{
		return Vector2(x + other.x, y + other.y);
	}
}