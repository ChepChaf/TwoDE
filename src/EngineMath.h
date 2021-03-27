#pragma once

#include "Core.h"
#include "Vector2.h"

#include <cmath>

namespace TwoDE
{
	class TWO_DLL EngineMath
	{
	public:
		static const double PI;
		static float clamp(float v, float min, float max);
		static Vector2 clamp(Vector2 v, float min, float max);
		static float toDeg(float rad);
	};
}


