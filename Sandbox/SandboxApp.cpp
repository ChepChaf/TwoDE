#include "SandboxApp.h"

#include <iostream>

void SandboxApp::start()
{
	std::cout << "Hello from SandboxApp" << std::endl;

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
}

void SandboxApp::update()
{
	TwoDE::Application::update();
	renderer->clear(TwoDE::Color(0.2f, 0.4f, 0.6f, 1.0f));

	if (sprite->getPosition().getX() > 1.0 || sprite->getPosition().getX() < -1.0)
		speed *= -1;
	sprite->setPosition(sprite->getPosition() + (TwoDE::EngineTime::deltaTime * speed));
}