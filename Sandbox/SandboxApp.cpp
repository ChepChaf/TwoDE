#include "SandboxApp.h"

#include <iostream>

void SandboxApp::start()
{
	TWODE_INFO("Hello from SandboxApp");

	sprite = resourceManager->loadSprite("resources/sprites/Character01.png");
	renderer->drawSprite(sprite);

	// 5 tiles
	std::shared_ptr<TwoDE::Texture> tile = resourceManager->loadTexture("resources/sprites/Tile01.png");

	TwoDE::Sprite sprite01 = TwoDE::Sprite(tile, TwoDE::Vector2(-1.0f, 1.0f));
	renderer->drawSprite(std::make_shared<TwoDE::Sprite>(sprite01));

	TwoDE::Sprite sprite02 = TwoDE::Sprite(tile, TwoDE::Vector2(-0.5f, 1.0f));
	renderer->drawSprite(std::make_shared<TwoDE::Sprite>(sprite02));

	TwoDE::Sprite sprite03 = TwoDE::Sprite(tile, TwoDE::Vector2(0.0f, 1.0f));
	renderer->drawSprite(std::make_shared<TwoDE::Sprite>(sprite03));

	TwoDE::Sprite sprite04 = TwoDE::Sprite(tile, TwoDE::Vector2(-1.0f, -1.0f));
	renderer->drawSprite(std::make_shared<TwoDE::Sprite>(sprite04));

	TwoDE::Sprite sprite05 = TwoDE::Sprite(tile, TwoDE::Vector2(1.0f, -1.0f));
	renderer->drawSprite(std::make_shared<TwoDE::Sprite>(sprite05));

	onEvent("button_clicked", TwoDE::Event(std::function([=](TwoDE::Input::ButtonEventInfo& params) 
		{
			TwoDE::Vector2 right{ 1, 0 };
			TwoDE::Vector2 up{ 0, 1 };

			switch (params.button)
			{
			case TwoDE::Input::BUTTON::RIGHT_KEY:
				sprite->setPosition(sprite->getPosition() + right * (speed * TwoDE::EngineTime::deltaTime));
				break;
			case TwoDE::Input::BUTTON::LEFT_KEY:
				sprite->setPosition(sprite->getPosition() + right * (-1 * speed * TwoDE::EngineTime::deltaTime));
				break;
			case TwoDE::Input::BUTTON::UP_KEY:
				sprite->setPosition(sprite->getPosition() + up * (speed * TwoDE::EngineTime::deltaTime));
				break;
			case TwoDE::Input::BUTTON::DOWN_KEY:
				sprite->setPosition(sprite->getPosition() + up * (-1 * speed * TwoDE::EngineTime::deltaTime));
				break;
			}
		}
	)));

	onEvent("button_released", TwoDE::Event(std::function([=](TwoDE::Input::ButtonEventInfo& params)
		{
			if (params.button == TwoDE::Input::BUTTON::RIGHT_KEY)
				TWODE_INFO("Released the right key.");
		}
	)));

	onEvent("mouse_click", TwoDE::Event(std::function([=](TwoDE::Input::MouseEventInfo& params)
		{
			if (params.button == TwoDE::Input::MOUSE_BUTTON::LEFT_BUTTON)
			{
				TWODE_INFO("Mouse x position: {}", params.position.getX());
				TWODE_INFO("Mouse y position: {}", params.position.getY());
				dragging = true;
			}
			if (params.button == TwoDE::Input::MOUSE_BUTTON::RIGHT_BUTTON)
			{
				sprite->rotate(-1);
			}
		}
	)));

	onEvent("mouse_release", TwoDE::Event(std::function([=](TwoDE::Input::MouseEventInfo& params)
		{
			if (params.button == TwoDE::Input::MOUSE_BUTTON::LEFT_BUTTON)
				dragging = false;
		}
	)));

	onEvent("mouse_scroll", TwoDE::Event(std::function([=](TwoDE::Input::ScrollEventInfo& params)
		{
			TwoDE::Vector2 scale = TwoDE::Vector2{ params.offset.getY(), params.offset.getY() };

			camera.get()->m_Transform.scale(scale*TwoDE::EngineTime::deltaTime);
		}
	)));
}

void SandboxApp::update()
{
	TwoDE::Application::update();

	if (dragging)
	{
		TwoDE::Vector2 position = TwoDE::Locator::getInputSystem().getCursorPosition() - camera.get()->m_Transform.setPosition();

		camera.get()->m_Transform.translate(position);
	}
		
	renderer->clear(TwoDE::Color(0.2f, 0.4f, 0.6f, 1.0f));
}