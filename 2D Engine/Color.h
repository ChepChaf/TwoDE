#pragma once

#include "Core.h"

namespace TwoDE
{
	class TWO_DLL Color
	{
		// TODO: Create a Vector4 class to use here
		float m_r, m_g, m_b, m_a;

	public:
		Color(float r, float g, float b, float a);

		inline float r(){ return m_r; }
		inline float g(){ return m_g; }
		inline float b(){ return m_b; }
		inline float alpha(){ return m_a; }
	};
}

