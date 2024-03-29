#pragma once

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
		
		Shader defaultShader;

		unsigned int vao = 0;
		unsigned int vbo = 0;

		float m_Width = 0.0; 
		float m_Height = 0.0;

		glm::mat4 projection;
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		// Inherited via Renderer
		virtual void drawSprite(Entity& entity, Sprite const& sprite, Transform const& transform) override;
		virtual Entity drawSprite(Sprite const& sprite, Transform const& transform) override;
		virtual Entity drawLine(glm::vec3 origin, glm::vec3 end, Color color, int width) override;
		virtual Entity drawRect(glm::vec3 origin, glm::vec2 size, Color color) override;
		virtual Entity drawCircle(glm::vec3 center, float radius, Color color, float quality=512.f) override;
		virtual int init(int widht, int height) override;
		virtual void clear(Color clearColor) override;
		virtual void draw(Transform& viewport) override;

		void checkGLError();
	};

}
