#pragma once

#include "Sprite.h"
#include "Color.h"
#include "Camera.h"
#include "Vector3.h"

namespace TwoDE
{
	class Renderer
	{
	public:
		virtual std::shared_ptr<Sprite> drawSprite(std::shared_ptr<Sprite> sprite) = 0;
		virtual std::shared_ptr<Sprite> drawLine(Vector3 origin, Vector3 end, Color color, int width) = 0;
		virtual std::shared_ptr<Sprite> drawRect(Vector3 origin, Vector2 size, Color color) = 0;
		virtual std::shared_ptr<Sprite> drawCircle(Vector3 center, float radius, Color color, float quality=512.f) = 0;

		virtual void draw(Camera& viewport) = 0;
		virtual int init(int width, int height) = 0;
		virtual void clear(Color clearColor) = 0;

		static Renderer* createRenderer();
	};
}
