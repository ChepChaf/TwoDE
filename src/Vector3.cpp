#include "Vector3.h"
#include <cmath>

namespace TwoDE
{
	void Vector3::operator+=(Vector3 other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void Vector3::operator+=(Vector2 other)
	{
		x += other.getX();
		y += other.getY();
	}

	Vector3 Vector3::operator+(Vector3 other)
	{
		return Vector3{ x + other.x, y + other.y, z + other.z };
	}

	Vector3 Vector3::operator+(float scalar)
	{
		return Vector3{x + scalar, y + scalar, z + scalar};
	}

	Vector3 Vector3::operator-(Vector3 other)
	{
		return Vector3{ x - other.x, y - other.y, z - other.z };
	}
	Vector3 Vector3::operator-(float scalar)
	{
		return Vector3{ x - scalar, y - scalar, z - scalar };
	}

	Vector3 Vector3::operator+(Vector2 other)
	{
		return Vector3{ x + other.getX(), y + other.getY(), z };
	}

	Vector3 Vector3::operator*(float scalar)
	{
		return Vector3{x * scalar, y * scalar, z * scalar};
	}

	float Vector3::dot(Vector3 other)
	{
		return x*other.x + y*other.y + z*other.z;
	}

	Vector3 Vector3::normalize()
	{
		float mag = magnitude();
		return Vector3{ x/mag, y/mag, z/mag };
	}

	float Vector3::magnitude()
	{
		return sqrt(x*x + y*y + z*z);
	}
}
