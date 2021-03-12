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

	TwoDE::Locator::getEventSystem().subscribe("button_clicked", TwoDE::Event(std::function([=](TwoDE::Input::ButtonEventInfo& params) {
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
	})));
}

void SandboxApp::update()
{
	TwoDE::Application::update();
	renderer->clear(TwoDE::Color(0.2f, 0.4f, 0.6f, 1.0f));
}