#pragma once

#include "Core.h"
#include "Vector2.h"
#include "Vector3.h"

namespace TwoDE
{
	class TWO_DLL Matrix4
	{
	public:
		float *mat;

		Matrix4();
		Matrix4(float val);
		Matrix4(float *val);

		const float *value_ptr();

		void translate(Vector2 vec);
		void translate(Vector3 vec);
		void rotate(float angle);
		void scale(Vector2 vec);
	};
}
