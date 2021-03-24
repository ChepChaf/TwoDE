#pragma once

namespace TwoDE
{
	class Texture
	{
	public:
		bool binded = false;
		unsigned int ID;
		int m_Width, m_Height, m_Channels;
		unsigned char* data;
	};
}


