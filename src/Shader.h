#pragma once

#include <glm/glm.hpp>

#include <string>

namespace TwoDE
{
    class Shader
    {
    public:
        unsigned int ID = 0;

        Shader(){}
        Shader(const char* vertexPath, const char* fragmentPath);

        void use();

        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
        void setFloat2(const std::string& name, float x, float y) const;
        void setFloat3(const std::string& name, float x, float y, float z) const;
        void setFloat4(const std::string& name, float x, float y, float z, float w) const;
        void setVector2(const std::string& name, glm::vec2 value) const;
        void setMatrix4(const std::string& name, glm::mat4 value) const;
    };
}
