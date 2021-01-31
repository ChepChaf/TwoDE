#pragma once
#include "Renderer.h"
#include "Sprite.h"
#include "Color.h"

namespace TwoDE
{
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		// Inherited via Renderer
		virtual void drawSprite(Sprite& sprite) override;
		virtual int init(int widht, int height) override;
		virtual void clear(Color clearColor) override;
	};
}
