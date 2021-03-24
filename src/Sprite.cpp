#include "Sprite.h"


namespace TwoDE
{
	Sprite::Sprite(std::shared_ptr<Texture> texture, Vector2 pos) : m_Texture(texture)
	{
		m_Transform = Transform(Vector3(pos.getX(), pos.getY(), 0.0f));
	}
	Sprite::Sprite(std::shared_ptr<Texture> texture, Transform transform) : m_Texture(texture), m_Transform(transform)
	{
	}

	void Sprite::setTexture(std::shared_ptr<Texture> texture)
	{
		m_Texture = texture;
	}

	void Sprite::setPosition(Vector3 position)
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
		return Vector2{ m_Transform.getPosition().x, m_Transform.getPosition().y };
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
	Transform* Sprite::getTransform()
	{
		return &m_Transform;
	}
	void Sprite::setZLevel(int level)
	{
		m_Transform.setZ(level);
	}
	bool Sprite::operator<(Sprite const& sp) const
	{
		return m_Transform.m_Position.z <= sp.m_Transform.m_Position.z;
	}
}

