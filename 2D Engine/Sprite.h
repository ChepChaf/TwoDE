#pragma once

#include "Core.h"

#include "Transform.h"
#include "Texture.h"
#include "Vector2.h"

#include <memory>

namespace TwoDE
{
	class TWO_DLL Sprite
	{
		Transform m_Transform;
		std::shared_ptr<Texture> m_Texture;

	public:
		Sprite() {}
		Sprite(std::shared_ptr<Texture> texture, Transform transform);

		void setTexture(std::shared_ptr<Texture> texture);
		void setPosition(Vector2 position);
		void setRotation(Vector2 setRotation);
		void setTransform(Transform transform);

		Vector2 getPosition();
		std::shared_ptr<Texture> getTexture();
	};
}

