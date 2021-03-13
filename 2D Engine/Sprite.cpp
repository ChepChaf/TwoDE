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

	void Sprite::setRotation(float rotation)
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

	void Sprite::scale(Vector2 scale)
	{
		m_Transform.scale(scale);
	}

	void Sprite::rotate(float angle)
	{
		m_Transform.rotate(angle);
	}

	std::shared_ptr<Texture> Sprite::getTexture()
	{
		return m_Texture;
	}
	const Transform* Sprite::getTransform() const
	{
		return &m_Transform;
	}
}

