#pragma once

#include<glm/glm.hpp>

#include "Core.h"
#include "Vector2.h"
#include "Vector3.h"

namespace TwoDE
{
	class TWO_DLL Matrix4
	{
	public:
		glm::mat4 m_Mat{ 1.f };

		Matrix4(){}
		Matrix4(float val) : m_Mat(glm::mat4(val)) {}

		const float* value_ptr();

		void translate(Vector2 vec);
		void translate(Vector3 vec);
		void rotate(float angle);
		void scale(Vector2 vec);
	};
}

