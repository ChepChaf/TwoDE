#include "Logger.h"
#include "ResourceManager.h"
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

#include <iostream>

namespace TwoDE
{
    std::shared_ptr<Sprite> ResourceManager::loadSprite(std::string spritePath)
    {
        if (loadedTextures.contains(spritePath) && loadedTextures[spritePath] != nullptr)
            return std::make_shared<Sprite>(Sprite(loadedTextures[spritePath], Vector2(0.0f, 0.0f)));

        std::shared_ptr<Texture> texture = loadTexture(spritePath);

        if (texture->data != NULL)
        {
            std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(texture, Vector2(0, 0));

            return sprite;
        }

        TWODE_CORE_ERROR("Error loading sprite");
        // TODO: Log error

        return nullptr;
    }
    std::shared_ptr<Texture> ResourceManager::loadTexture(std::string texturePath)
    {
        if (loadedTextures.contains(texturePath) && loadedTextures[texturePath] != nullptr)
            return loadedTextures[texturePath];

        stbi_set_flip_vertically_on_load(true);

        std::shared_ptr<Texture> texture = std::make_shared<Texture>();
        texture->data = stbi_load(texturePath.c_str(), &texture->m_Width, &texture->m_Height, &texture->m_Channels, 0);

        if (texture->data != NULL)
        {
            return texture;
        }

        TWODE_CORE_ERROR("Error loading sprite");
        // TODO: Log error

        return nullptr;
    }
}
