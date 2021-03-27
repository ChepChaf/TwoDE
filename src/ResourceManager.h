#pragma once

#include "Core.h"

#include "Sprite.h"
#include "Texture.h"
#include "Color.h"

#include <string>
#include <unordered_map>
#include <memory>

namespace TwoDE
{
	class TWO_DLL ResourceManager
	{
		std::unordered_map<std::string, std::shared_ptr<Sprite>> loadedSprites;
		std::unordered_map<std::string, std::shared_ptr<Texture>> loadedTextures;
		std::unordered_map<long, std::shared_ptr<Texture>> colorTextures;
		std::unordered_map<long, std::shared_ptr<Texture>> circleTextures;
	public:
		std::shared_ptr<Sprite> loadSprite(std::string spritePath);
		std::shared_ptr<Texture> loadTexture(std::string texturePath);
		std::shared_ptr<Texture> getSolidColorTexture(Color color);
		std::shared_ptr<Texture> getCircleTexture(Color color, float width=128.f);

		void init();
	};
}

