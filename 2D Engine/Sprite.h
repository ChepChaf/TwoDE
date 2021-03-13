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
		void setRotation(float setRotation);
		void setTransform(Transform transform);

		void scale(Vector2 scale);
		void rotate(float angle);

		Vector2 getPosition();
		std::shared_ptr<Texture> getTexture();
		const Transform* getTransform() const;
	};
}

