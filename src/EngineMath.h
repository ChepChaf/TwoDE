#pragma once

#include "Core.h"
#include "Vector2.h"

namespace TwoDE
{
	class TWO_DLL EngineMath
	{
	public:
		static float clamp(float v, float min, float max);
		static Vector2 clamp(Vector2 v, float min, float max);
	};
}


