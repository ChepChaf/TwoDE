#pragma once

#include "Sprite.h"
#include "Color.h"

namespace TwoDE
{
	class Renderer
	{
	public:
		virtual void drawSprite(std::shared_ptr<Sprite> sprite) = 0;
		virtual void draw() = 0;
		virtual int init(int width, int height) = 0;
		virtual void clear(Color clearColor) = 0;

		static Renderer* createRenderer();
	};
}
