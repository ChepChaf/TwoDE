#include "Matrix4.h"

#include <glm/gtc/type_ptr.hpp>

namespace TwoDE
{
    const float* Matrix4::value_ptr()
    {
        return glm::value_ptr(m_Mat);
    }
    void Matrix4::translate(Vector2 vec)
    {
        m_Mat = glm::translate(m_Mat, glm::vec3(vec.getX(), vec.getY(), 0.0f));
    }
    void Matrix4::rotate(float angle)
    {
        m_Mat = glm::rotate(m_Mat, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));
    }
    void Matrix4::scale(Vector2 vec)
    {
        m_Mat = glm::scale(m_Mat, glm::vec3(vec.getX(), vec.getY(), 1.0f));
    }
}
