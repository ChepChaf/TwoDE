#pragma once

#include "Sprite.h"
#include "Transform.h"
#include "Color.h"
#include <glm/glm.hpp>
#include "Scene.h"

namespace TwoDE
{
	class Renderer
	{
	public:
		virtual void drawSprite(Entity& entity, Sprite const& sprite, Transform const& transform) = 0;
		virtual Entity drawSprite(Sprite const& sprite, Transform const& transform) = 0;
		virtual Entity drawLine(glm::vec3 origin, glm::vec3 end, Color color, int width) = 0;
		virtual Entity drawRect(glm::vec3 origin, glm::vec2 size, Color color) = 0;
		virtual Entity drawCircle(glm::vec3 center, float radius, Color color, float quality=512.f) = 0;

		virtual void draw(Transform& viewport) = 0;
		virtual int init(int width, int height) = 0;
		virtual void clear(Color clearColor) = 0;

		static Renderer* createRenderer();
	};
}
