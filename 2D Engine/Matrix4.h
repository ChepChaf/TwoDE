#pragma once

#include<glm/glm.hpp>

#include "Core.h"
#include "Vector2.h"

namespace TwoDE
{
	class TWO_DLL Matrix4
	{
		glm::mat4 m_Mat{ 1.f };
	public:
		

		Matrix4(){}
		Matrix4(float val) : m_Mat(glm::mat4(val)) {}

		const float* value_ptr();

		void translate(Vector2 vec);
		void rotate(float angle);
		void scale(Vector2 vec);
	};
}

