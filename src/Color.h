#pragma once

#include "Core.h"
#include <functional>
#include <string>

namespace TwoDE
{
	class TWO_DLL Color
	{
		// TODO: Create a Vector4 class to use here
		float m_r, m_g, m_b, m_a;

	public:
		Color(float r, float g, float b, float a) : m_r(r), m_g(g), m_b(b), m_a(a){}

		inline float r(){ return m_r; }
		inline float g(){ return m_g; }
		inline float b(){ return m_b; }
		inline float alpha(){ return m_a; }
	};
}

namespace std
{
	template <>
	struct hash<TwoDE::Color>
	{
		std::size_t operator()(TwoDE::Color& k) const
		{
			using std::size_t;
			using std::hash;
			using std::string;

			// Compute individual hash values for first,
			// second and third and combine them using XOR
			// and bit shifting:

			return ((hash<float>()(k.r())
				^ (hash<float>()(k.g()) << 1)) >> 1)
				^ (hash<float>()(k.b()) << 1)
				^ (hash<float>()(k.alpha()) << 1);
		}
	};
}

