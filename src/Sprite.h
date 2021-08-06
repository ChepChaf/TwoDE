#pragma once

#include "Core.h"

#include <string>
#include <array>

namespace TwoDE
{
	class TWO_DLL Sprite
	{
	public:
		bool binded{ false };
		unsigned int ID{ 0 };
		int m_Width{ 0 }; 
		int m_Height{ 0 };
		int m_Channels{ 0 };
		
		unsigned char* data = nullptr;

		Sprite() = default;
		Sprite(std::string const& path);
		~Sprite() = default;
	};
}

