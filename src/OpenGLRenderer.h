#pragma once

#include "glad/glad.h"

#include "Renderer.h"
#include "Sprite.h"
#include "Color.h"
#include "Shader.h"

#include <list>
#include <memory>

namespace TwoDE
{
	class OpenGLRenderer : public Renderer
	{
		static const int maxNumberSprites = 100;
		
		std::list<std::shared_ptr<Sprite>> sprites;

		Shader defaultShader;

		unsigned int vao = 0;
		unsigned int vbo = 0;

		float m_Width = 0.0; 
		float m_Height = 0.0;
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		// Inherited via Renderer
		virtual void drawSprite(std::shared_ptr<Sprite> sprite) override;
		virtual int init(int widht, int height) override;
		virtual void clear(Color clearColor) override;
		virtual void draw(Camera& viewport) override;

		void checkGLError();
		//void GLAPIENTRY messageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	};

}
