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

		void resortSprites();
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		// Inherited via Renderer
		virtual std::shared_ptr<Sprite> drawSprite(std::shared_ptr<Sprite> sprite) override;
		virtual std::shared_ptr<Sprite> drawLine(Vector3 origin, Vector3 end, Color color, int width) override;
		virtual std::shared_ptr<Sprite> drawRect(Vector3 origin, Vector2 size, Color color) override;
		virtual std::shared_ptr<Sprite> drawCircle(Vector3 center, float radius, Color color, float quality=512.f) override;
		virtual int init(int widht, int height) override;
		virtual void clear(Color clearColor) override;
		virtual void draw(Camera& viewport) override;


		void checkGLError();
	};

}
