#include "Logger.h"
#include "ResourceManager.h"
#include "Texture.h"

#include "stb_image/stb_image.h"

#include <iostream>
#include <functional>

namespace TwoDE
{
    std::shared_ptr<Sprite> ResourceManager::loadSprite(std::string spritePath)
    {
        if (loadedTextures.find(spritePath) != loadedTextures.end() && loadedTextures[spritePath] != nullptr)
            return std::make_shared<Sprite>(Sprite(loadedTextures[spritePath], Vector3(0.0f, 0.0f, 0.0f)));

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
        if (loadedTextures.find(texturePath) != loadedTextures.end() && loadedTextures[texturePath] != nullptr)
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
    std::shared_ptr<Texture> ResourceManager::getSolidColorTexture(Color color)
    {
        long colorHash = std::hash<Color>{}(color);

        if (colorTextures.find(colorHash) != colorTextures.end())
        {
            TWODE_CORE_INFO("Found line texture: {}", colorHash);
            return colorTextures[colorHash];
        }

        Texture tex;
        tex.m_Width = 1;
        tex.m_Height = 1;
        tex.m_Channels = 4;

        tex.data = new unsigned char[4];
        tex.data[0] = color.r() * 255;
        tex.data[1] = color.g() * 255;
        tex.data[2] = color.b() * 255;
        tex.data[3] = color.alpha() * 255;
          

        colorTextures[colorHash] = std::make_shared<Texture>(tex);

        return colorTextures[colorHash];
    }
    std::shared_ptr<Texture> ResourceManager::getCircleTexture(Color color, float radius)
    {
        long colorHash = std::hash<Color>{}(color);

        if (circleTextures.find(colorHash) != circleTextures.end())
        {
            TWODE_CORE_INFO("Found circle texture: {}", colorHash);
            return circleTextures[colorHash];
        }

        Texture tex;
        tex.m_Width = radius * 2;
        tex.m_Height = radius * 2;
        tex.m_Channels = 4;

        int n = static_cast<int>(tex.m_Width * tex.m_Height * tex.m_Channels);
        tex.data = new unsigned char[n];

        unsigned char red = static_cast<unsigned char>(color.r() * 255);
        unsigned char green= static_cast<unsigned char>(color.g() * 255);
        unsigned char blue = static_cast<unsigned char>(color.b() * 255);
        
        for (int i = 0; i < n; i += 4)
        {
            int index = i;
            *(tex.data + index++) = red;
            *(tex.data + index++) = green;
            *(tex.data + index++) = blue;

            float y = static_cast<int>(i / (radius * 2)) / 4 - radius;
            int x = (i / 4) % static_cast<int>(radius * 2) - radius;

            float eq = x * x + y * y;

            if (x == 0 && y == 0)
                TWODE_CORE_INFO("");

            unsigned char alpha = 255;

            if (eq >= radius * radius)
                alpha = 0;
            else if (eq == radius * radius)
                alpha = 128;

            *(tex.data + index) = alpha;
        }
        

        circleTextures[colorHash] = std::make_shared<Texture>(tex);

        return circleTextures[colorHash];
    }

    void ResourceManager::init()
    {
    }
}
