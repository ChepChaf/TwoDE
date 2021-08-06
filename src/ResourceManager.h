#pragma once

#include "Core.h"

#include "Sprite.h"
#include "Color.h"

#include <string>
#include <unordered_map>
#include <memory>

namespace TwoDE
{
	class TWO_DLL ResourceManager
	{
		std::unordered_map<std::string, Sprite> loadedSprites;
		std::unordered_map<long, Sprite> colorTextures;
		std::unordered_map<long, Sprite> circleTextures;
	public:
		Sprite loadSprite(std::string spritePath);
		Sprite getSolidColorTexture(Color color);
		Sprite getCircleTexture(Color color, float width=128.f);

		void init();
	};
}

