#include "Logger.h"
#include "OpenGLRenderer.h"

#include "glad/glad.h"

#include <iostream>

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
	void OpenGLRenderer::drawSprite(std::shared_ptr<Sprite> sprite)
	{
		sprites.push_back(sprite);
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

		defaultShader = Shader("resources/shaders/default.vert", "resources/shaders/default.frag");

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
		OpenGLRenderer::defaultShader.setMatrix4("view", viewport.m_Transform.getMatrix());

		unsigned int ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		for (int i = 0; i < sprites.size(); i++)
		{
			glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(square), 16 * sizeof(float), square);

			OpenGLRenderer::defaultShader.setMatrix4("transform", sprites[i]->getTransform()->getMatrix());

			std::shared_ptr<Texture> texture = sprites[i]->getTexture();

			if (!texture->binded)
			{
				glGenTextures(1, &texture->ID);

				glBindTexture(GL_TEXTURE_2D, texture->ID);

				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->m_Width, texture->m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
				glGenerateMipmap(GL_TEXTURE_2D);

				texture->binded = true;
			}

			OpenGLRenderer::defaultShader.setInt("texture1", 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture->ID);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
	}
}