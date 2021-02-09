#include "Sprite.h"


namespace TwoDE
{
	Sprite::Sprite(std::shared_ptr<Texture> texture, Transform transform) : m_Texture(texture), m_Transform(transform)
	{
		m_Texture = texture;
		m_Transform = transform;
	}

	void Sprite::setTexture(std::shared_ptr<Texture> texture)
	{
		m_Texture = texture;
	}

	void Sprite::setPosition(Vector2 position)
	{
		m_Transform.setPosition(position);
	}

	void Sprite::setRotation(Vector2 rotation)
	{
		m_Transform.setRotation(rotation);
	}

	void Sprite::setTransform(Transform transform)
	{
		m_Transform = transform;
	}
	Vector2 Sprite::getPosition()
	{
		return m_Transform.setPosition();
	}

	std::shared_ptr<Texture> Sprite::getTexture()
	{
		return m_Texture;
	}
}

