#include "Matrix4.h"

#include <glm/gtc/type_ptr.hpp>

namespace TwoDE
{
    const float* Matrix4::value_ptr()
    {
        return glm::value_ptr(mat);
    }
    void Matrix4::translate(Vector2 vec)
    {
        mat = glm::translate(mat, glm::vec3(vec.getX(), vec.getY(), 0.0f));
    }
    void Matrix4::translate(Vector3 vec)
    {
        mat = glm::translate(mat, glm::vec3(vec.x, vec.y, vec.z));
    }
    void Matrix4::rotate(float angle)
    {
        mat = glm::rotate(mat, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));
    }
    void Matrix4::scale(Vector2 vec)
    {
        mat = glm::scale(mat, glm::vec3(vec.getX(), vec.getY(), 1.0f));
    }
}
