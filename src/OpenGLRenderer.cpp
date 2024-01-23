#include "GL/glew.h"

#include "Logger.h"
#include "OpenGLRenderer.h"
#include "Locator.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <cmath>

void GLAPIENTRY
messageCallback(GLenum source,
                GLenum type,
                GLuint id,
                GLenum severity,
                GLsizei length,
                const GLchar *message,
                const void *userParam)
{
    std::cerr << "GL CALLBACK: " << (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "") << "type = " << type << "\nseverity = " << severity << "\nmessage = " << message << std::endl;
}

namespace TwoDE
{
    OpenGLRenderer::OpenGLRenderer()
    {
    }

    OpenGLRenderer::~OpenGLRenderer()
    {
    }

    void OpenGLRenderer::drawSprite(Entity &entity, Sprite const &sprite, Transform const &transform)
    {
        Locator::getLocator().getSceneManagerSystem().AddComponent<Sprite>(entity, sprite);
        Locator::getLocator().getSceneManagerSystem().AddComponent<Transform>(entity, transform);
    }

    Entity OpenGLRenderer::drawSprite(Sprite const &sprite, Transform const &transform)
    {
        Entity ent = Locator::getLocator().getSceneManagerSystem().CreateEntity();

        drawSprite(ent, sprite, transform);

        return ent;
    }

    Entity OpenGLRenderer::drawLine(glm::vec3 origin, glm::vec3 end, Color color, int width)
    {
        glm::vec3 dir = end - origin;
        float dirMagnitude = glm::length(dir);

        glm::vec3 normalizedDir = glm::normalize(dir);
        float dot = glm::dot(normalizedDir, glm::vec3{1, 0, 0});

        // Back to degrees
        float ang = glm::degrees(acos(dot));

        Transform trans;
        trans.setPosition(origin + glm::vec3{dir.x / 2, dir.y / 2, end.z});
        trans.setRotation(static_cast<int>(ang));
        trans.setScale(glm::vec3{dirMagnitude, static_cast<float>(width), 0.0f});

        const auto &sprite = Locator::getLocator().getResourceManagerSystem().getSolidColorTexture(color);

        return drawSprite(sprite, trans);
    }

    Entity OpenGLRenderer::drawRect(glm::vec3 origin, glm::vec2 size, Color color)
    {
        Transform trans;

        trans.setScale(glm::vec3{size, 0.0f});
        size *= 0.5f;
        trans.setPosition(origin + glm::vec3{size.x, size.y, 0.0});

        const auto &sprite = Locator::getLocator().getResourceManagerSystem().getSolidColorTexture(color);

        return drawSprite(sprite, trans);
    }

    Entity OpenGLRenderer::drawCircle(glm::vec3 center, float radius, Color color, float quality)
    {
        Transform trans;

        trans.setScale(glm::vec3{radius, radius, 0.0f});
        trans.setPosition(center);

        const auto &sprite = Locator::getLocator().getResourceManagerSystem().getCircleTexture(color);

        return drawSprite(sprite, trans);
    }

    void OpenGLRenderer::checkGLError()
    {
        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR)
        {
            TWODE_CORE_ERROR(err);
        }
    }

    int OpenGLRenderer::init(int width, int height)
    {
        GLenum err = glewInit();
        if (GLEW_OK != err)
            return -1;

        m_Width = width;
        m_Height = height;
        glViewport(0, 0, width, height);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);

        glEnable(GL_DEBUG_OUTPUT);
        // glDebugMessageCallback(messageCallback, 0);
        // glDebugMessageControl(GL_DONT_CARE, GL_DEBUG_TYPE_OTHER, GL_DEBUG_SEVERITY_NOTIFICATION, 0, 0, GL_FALSE);

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float) * maxNumberSprites, 0, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // glEnable(GL_ALPHA_TEST);
        // glEnable(GL_DEPTH_TEST);

        defaultShader = Shader("resources/shaders/default.vert", "resources/shaders/default.frag");
        defaultShader.use();
        OpenGLRenderer::defaultShader.setInt("texture1", 0);
        glActiveTexture(GL_TEXTURE0);

        projection = glm::ortho(0.0f, m_Width, 0.0f, m_Height, -10.0f, 10.0f);
        
        OpenGLRenderer::defaultShader.setMatrix4("projection", projection);

        return 0;
    }

    void OpenGLRenderer::clear(Color clearColor)
    {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.alpha);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OpenGLRenderer::draw(Transform &viewport)
    {
        float square[] = {
            0.5f, 0.5f, 1.f, 1.f,
            0.5f, -0.5f, 1.f, 0.f,
            -0.5f, -0.5f, 0.f, 0.f,
            -0.5f, 0.5f, 0.f, 1.f};

        unsigned int indices[]{
            0, 2, 1,
            0, 3, 2};

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        unsigned int ebo;
        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

        OpenGLRenderer::defaultShader.setMatrix4("view", viewport.getMatrix());

        auto registry = Locator::getLocator().getSceneManagerSystem().GetRegistry();

        registry->sort<Sprite>([&](const entt::entity lhs, const entt::entity rhs)
                               {
            const auto &lTrans = registry->get<Transform>(lhs);
            const auto &rTrans = registry->get<Transform>(rhs);

            return lTrans.m_Position.z < rTrans.m_Position.z; });

        auto view = registry->view<Sprite, Transform>();

        int i = 0;
        for (auto entity : view)
        {
            auto &sprite = view.get<Sprite>(entity);
            auto &transform = view.get<Transform>(entity);

            glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(square), 16 * sizeof(float), square);

            OpenGLRenderer::defaultShader.setMatrix4("transform", transform.getMatrix());

            if (!sprite.binded)
            {
                glGenTextures(1, &sprite.ID);

                glBindTexture(GL_TEXTURE_2D, sprite.ID);

                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sprite.m_Width, sprite.m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                             sprite.data);
                glGenerateMipmap(GL_TEXTURE_2D);

                sprite.binded = true;
            }

            OpenGLRenderer::defaultShader.setFloat3("material.diffuse", sprite.color.r, sprite.color.g, sprite.color.b);
            glBindTexture(GL_TEXTURE_2D, sprite.ID);

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            i++;
        }
    }
}
