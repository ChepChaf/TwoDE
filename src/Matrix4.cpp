#include "Matrix4.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace TwoDE
{
    Matrix4::Matrix4()
    {
        mat = new float[16];
        auto val = glm::value_ptr(glm::mat4(1.0f));
        memcpy(mat, val, sizeof(float) * 16);
    }
    Matrix4::Matrix4(float val)
    {
        mat = new float[16];
        auto vPtr = glm::value_ptr(glm::mat4(val));
        memcpy(mat, vPtr, sizeof(float) * 16);
    }
    Matrix4::Matrix4(float *val)
    {
        mat = val;
    }
    const float *Matrix4::value_ptr()
    {
        return mat;
    }
    void Matrix4::translate(Vector2 vec)
    {
        auto temp = glm::make_mat4(mat);
        auto vPtr = glm::value_ptr(glm::translate(temp, glm::vec3(vec.getX(), vec.getY(), 0.0f)));
        memcpy(mat, vPtr, sizeof(float) * 16);
    }
    void Matrix4::translate(Vector3 vec)
    {
        auto temp = glm::make_mat4(mat);
        auto vPtr = glm::value_ptr(glm::translate(temp, glm::vec3(vec.x, vec.y, vec.z)));
        memcpy(mat, vPtr, sizeof(float) * 16);
    }
    void Matrix4::rotate(float angle)
    {
        auto temp = glm::make_mat4(mat);
        auto vPtr = glm::value_ptr(glm::rotate(temp, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f)));
        memcpy(mat, vPtr, sizeof(float) * 16);
    }
    void Matrix4::scale(Vector2 vec)
    {
        auto temp = glm::make_mat4(mat);
        auto vPtr = glm::value_ptr(glm::scale(temp, glm::vec3(vec.getX(), vec.getY(), 1.0f)));
        memcpy(mat, vPtr, sizeof(float) * 16);
    }
}
