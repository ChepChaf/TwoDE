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
	std::shared_ptr<Sprite> OpenGLRenderer::drawSprite(std::shared_ptr<Sprite> sprite)
	{
		sprites.push_back(sprite);

		resortSprites();

		return sprite;
	}

	std::shared_ptr<Sprite> OpenGLRenderer::drawLine(Vector3 origin, Vector3 end, Color color, int width)
	{
		Vector3 dir = end - origin;
		float dirMagnitude = dir.magnitude();

		Vector3 normalizedDir = dir.normalize();
		float dot = normalizedDir.dot(Vector3{ 1, 0, 0 });

		// Back to degrees
		float ang = EngineMath::toDeg(acos(dot));

		Transform trans;
		trans.setPosition(origin + Vector3{ dir.x/2, dir.y/2, end.z });
		trans.setRotation(static_cast<int>(ang));
		trans.setScale(Vector2{ dirMagnitude, static_cast<float>(width) });

		std::shared_ptr<Texture> tex = Locator::getResourceManagerSystem().getSolidColorTexture(color);

		Sprite sprite = Sprite(tex, trans);
		std::shared_ptr shrSprite = std::make_shared<Sprite>(sprite);

		drawSprite(shrSprite);

		return shrSprite;
	}

	std::shared_ptr<Sprite> OpenGLRenderer::drawRect(Vector3 origin, Vector2 size, Color color)
	{
		Transform trans;
		
		trans.setScale(size);
		trans.setPosition(origin + (size * 0.5f));

		std::shared_ptr<Texture> tex = Locator::getResourceManagerSystem().getSolidColorTexture(color);

		Sprite sprite = Sprite(tex, trans);
		std::shared_ptr shrSprite = std::make_shared<Sprite>(sprite);


		drawSprite(shrSprite);

		return shrSprite;
	}

	std::shared_ptr<Sprite> OpenGLRenderer::drawCircle(Vector3 center, float radius, Color color, float quality)
	{
		Transform trans;

		trans.setScale(Vector2{ radius, radius });
		trans.setPosition(center);

		std::shared_ptr<Texture> tex = Locator::getResourceManagerSystem().getCircleTexture(color);

		Sprite sprite = Sprite(tex, trans);

		std::shared_ptr shrSprite = std::make_shared<Sprite>(sprite);

		drawSprite(shrSprite);

		return shrSprite;
	}

	void OpenGLRenderer::resortSprites()
	{
		sprites.sort([](std::shared_ptr<Sprite> sp1, std::shared_ptr<Sprite> sp2)
			{
				return sp1->getTransform()->m_Position.z < sp2->getTransform()->m_Position.z;
			}
		);
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
	void OpenGLRenderer::draw(Camera& viewport)
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
		OpenGLRenderer::defaultShader.setMatrix4("view", viewport.m_Transform.getMatrix());

		unsigned int ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		int i = 0;
		for (auto sprite : sprites)
		{
			glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(square), 16 * sizeof(float), square);

			OpenGLRenderer::defaultShader.setMatrix4("transform", sprite->getTransform()->getMatrix());

			std::shared_ptr<Texture> texture = sprite->getTexture();

			if (!texture->binded)
			{
				glGenTextures(1, &texture->ID);

				glBindTexture(GL_TEXTURE_2D, texture->ID);

				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->m_Width, texture->m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
				glGenerateMipmap(GL_TEXTURE_2D);

				texture->binded = true;
			}

			glBindTexture(GL_TEXTURE_2D, texture->ID);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			i++;
		}
	}
}