#pragma once

#include "Transform.h"
#include "Texture.h"
#include "Vector2.h"

namespace TwoDE
{
	class Sprite
	{
		Transform m_Transform;
		Texture& m_Texture;
	public:
		void setTexture(Texture& texture);
		void setPosition(Vector2 position);
		void setRotation(Vector2 setRotation);
		void setTransform(Transform transform);
	};
}

