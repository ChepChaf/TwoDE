#pragma once

#include "Core.h"

#include "Sprite.h"
#include "Texture.h"

#include <string>
#include <map>
#include <memory>

namespace TwoDE
{
	class TWO_DLL ResourceManager
	{
		std::map<std::string, std::shared_ptr<Sprite>> loadedSprites;
		std::map<std::string, std::shared_ptr<Texture>> loadedTextures;

	public:
		std::shared_ptr<Sprite> loadSprite(std::string spritePath);
		std::shared_ptr<Texture> loadTexture(std::string texturePath);
	};
}

