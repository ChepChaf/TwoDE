#include "Logger.h"
#include "ResourceManager.h"

#include "stb_image/stb_image.h"

#include <iostream>
#include <functional>

namespace TwoDE
{
    Sprite ResourceManager::loadSprite(std::string spritePath)
    {
        if (loadedSprites.find(spritePath) != loadedSprites.end())
            return loadedSprites[spritePath];

        stbi_set_flip_vertically_on_load(true);

        Sprite texture;
        texture.data = stbi_load(spritePath.c_str(), &texture.m_Width, &texture.m_Height, &texture.m_Channels, 0);

        if (texture.data == NULL)
        {
            TWODE_CORE_ERROR("Error loading sprite {}", spritePath);
        }

        loadedSprites[spritePath] = texture;

        return loadedSprites[spritePath];
    }
    Sprite ResourceManager::getSolidColorTexture(Color color)
    {
        long colorHash = std::hash<Color>{}(color);

        if (colorTextures.find(colorHash) != colorTextures.end())
        {
            TWODE_CORE_INFO("Found line texture: {}", colorHash);
            return colorTextures[colorHash];
        }

        Sprite tex;
        tex.m_Width = 1;
        tex.m_Height = 1;
        tex.m_Channels = 4;

        tex.data = new unsigned char[4];
        tex.data[0] = 255;
        tex.data[1] = 255;
        tex.data[2] = 255;
        tex.data[3] = 255;

        tex.color = color;

        colorTextures[colorHash] = tex;

        return colorTextures[colorHash];
    }
    
    Sprite ResourceManager::getCircleTexture(Color color, float radius)
    {
        long colorHash = std::hash<Color>{}(color);

        if (circleTextures.find(colorHash) != circleTextures.end())
        {
            TWODE_CORE_INFO("Found circle texture: {}", colorHash);
            return circleTextures[colorHash];
        }

        Sprite tex;
        tex.m_Width = radius * 2;
        tex.m_Height = radius * 2;
        tex.m_Channels = 4;

        int n = static_cast<int>(tex.m_Width * tex.m_Height * tex.m_Channels);
        tex.data = new unsigned char[n];
        
        for (int i = 0; i < n; i += 4)
        {
            int index = i;
            *(tex.data + index++) = 255;
            *(tex.data + index++) = 255;
            *(tex.data + index++) = 255;

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

        tex.color = color;

        circleTextures[colorHash] = tex;

        return circleTextures[colorHash];
    }

    void ResourceManager::init()
    {
    }
}
