#include "Logger.h"
#include "OpenGLRenderer.h"
#include "Locator.h"
#include "EngineMath.h"

#include "glad/glad.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <cmath>

void GLAPIENTRY
messageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	std::cerr << "GL CALLBACK: " << (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "") <<
		"type = " << type << "\nseverity = " << severity << "\nmessage = " << message << std::endl;
}

namespace TwoDE
{
	OpenGLRenderer::OpenGLRenderer()
	{
	}
	OpenGLRenderer::~OpenGLRenderer()
	{
	}

	void OpenGLRenderer::drawSprite(Entity& entity, Sprite const& sprite, Transform const& transform)
	{
		Locator::getLocator().getSceneManagerSystem().AddComponent<Sprite>(entity, sprite);
		Locator::getLocator().getSceneManagerSystem().AddComponent<Transform>(entity, transform);
	}

	Entity OpenGLRenderer::drawSprite(Sprite const& sprite, Transform const& transform)
	{
		Entity ent = Locator::getLocator().getSceneManagerSystem().CreateEntity();
		
		drawSprite(ent, sprite, transform);

		return ent;
	}

	Entity OpenGLRenderer::drawLine(Vector3 origin, Vector3 end, Color color, int width)
	{
		Vector3 dir = end - origin;
		float dirMagnitude = dir.magnitude();

		Vector3 normalizedDir = dir.normalize();
		float dot = normalizedDir.dot(Vector3{ 1, 0, 0 });

		// Back to degrees
		float ang = EngineMath::toDeg(acos(dot));

		Transform trans;
		trans.setPosition(origin + Vector3{ dir.x / 2, dir.y / 2, end.z });
		trans.setRotation(static_cast<int>(ang));
		trans.setScale(Vector2{ dirMagnitude, static_cast<float>(width) });

		const auto& sprite = Locator::getLocator().getResourceManagerSystem().getSolidColorTexture(color);

		return drawSprite(sprite, trans);
	}

	Entity OpenGLRenderer::drawRect(Vector3 origin, Vector2 size, Color color)
	{
		Transform trans;

		trans.setScale(size);
		trans.setPosition(origin + (size * 0.5f));

		const auto& sprite = Locator::getLocator().getResourceManagerSystem().getSolidColorTexture(color);

		return drawSprite(sprite, trans);
	}

	Entity OpenGLRenderer::drawCircle(Vector3 center, float radius, Color color, float quality)
	{
		Transform trans;

		trans.setScale(Vector2{ radius, radius });
		trans.setPosition(center);

		const auto& sprite = Locator::getLocator().getResourceManagerSystem().getCircleTexture(color);

		return drawSprite(sprite, trans);
	}

	void OpenGLRenderer::checkGLError()
	{
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			TWODE_CORE_ERROR(err);
		}
	}

	int OpenGLRenderer::init(int width, int height)
	{
		// TODO: Find way to abstract this so it's not dependent on glfw
		if (!gladLoadGL())
			return -1;

		m_Width = width;
		m_Height = height;
		glViewport(0, 0, width, height);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(messageCallback, 0);
		glDebugMessageControl(GL_DONT_CARE, GL_DEBUG_TYPE_OTHER, GL_DEBUG_SEVERITY_NOTIFICATION, 0, 0, GL_FALSE);

		glCreateVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glCreateBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float) * maxNumberSprites, 0, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2* sizeof(float)));
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

		return 0;
	}

	void OpenGLRenderer::clear(Color clearColor)
	{
		glClearColor(clearColor.r(), clearColor.g(), clearColor.b(), clearColor.alpha());
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void OpenGLRenderer::draw(Transform& viewport)
	{
		float square[] = {
			0.5f, 0.5f, 1.f, 1.f,
			0.5f, -0.5f, 1.f, 0.f,
			-0.5f, -0.5f, 0.f, 0.f,
			-0.5f, 0.5f, 0.f, 1.f
		};

		unsigned int indices[]{
			0, 2, 1,
			0, 3, 2
		};

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		OpenGLRenderer::defaultShader.use();

		glm::mat4 ortho = glm::ortho(0.0f, m_Width, 0.0f, m_Height, -10.0f, 10.0f);
		Matrix4 projection;
		projection.m_Mat = ortho;

		OpenGLRenderer::defaultShader.setMatrix4("projection", projection);
		OpenGLRenderer::defaultShader.setMatrix4("view", viewport.getMatrix());

		unsigned int ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		auto registry = Locator::getLocator().getSceneManagerSystem().GetRegistry();

		registry->sort<Sprite>([&](const entt::entity lhs, const entt::entity rhs) {
			const auto& lTrans = registry->get<Transform>(lhs);
			const auto& rTrans = registry->get<Transform>(rhs);

			return lTrans.m_Position.z < rTrans.m_Position.z;
		});

		auto view = registry->view<Sprite, Transform>();

		int i = 0;
		for (auto entity : view)
		{
			auto& sprite = view.get<Sprite>(entity);
			auto& transform = view.get<Transform>(entity);

			glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(square), 16 * sizeof(float), square);

			OpenGLRenderer::defaultShader.setMatrix4("transform", transform.getMatrix());

			if (!sprite.binded)
			{
				glGenTextures(1, &sprite.ID);

				glBindTexture(GL_TEXTURE_2D, sprite.ID);

				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sprite.m_Width, sprite.m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, sprite.data);
				glGenerateMipmap(GL_TEXTURE_2D);

				sprite.binded = true;
			}

			glBindTexture(GL_TEXTURE_2D, sprite.ID);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			i++;
		}
	}
}