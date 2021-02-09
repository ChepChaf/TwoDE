#pragma once

#include "Vector2.h"

#include <string>

namespace TwoDE
{
    class Shader
    {
    public:
        unsigned int ID;

        Shader(){}
        Shader(const char* vertexPath, const char* fragmentPath);

        void use();

        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
        void setFloat2(const std::string& name, float x, float y) const;
        void setVector2(const std::string& name, Vector2 value) const;
    };
}
