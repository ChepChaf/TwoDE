#include "Sprite.h"
#include "Locator.h"

namespace TwoDE
{
	Sprite::Sprite(std::string const& path)
	{
		const auto& sp = Locator::getLocator().getResourceManagerSystem().loadSprite(path);

		binded = sp.binded;
		ID = sp.ID;

		m_Width = sp.m_Width;
		m_Height = sp.m_Height;
		m_Channels = sp.m_Channels;
		data = sp.data;
	}
}

