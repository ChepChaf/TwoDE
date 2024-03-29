#include "SandboxApp.h"

#include <iostream>

void SandboxApp::start()
{
	TWODE_INFO("Hello from SandboxApp");

	player = TwoDE::Locator::getLocator().getSceneManagerSystem().CreateEntity();
	
	renderer->drawSprite(player, TwoDE::Sprite("resources/sprites/Character01.png"), glm::vec3{ 0.0f, 0.0f, 1.0f });
	
	// 5 tiles
	TwoDE::Sprite tile{ "resources/sprites/Tile01.png" };

	renderer->drawSprite(tile, { { 0.f,  0.f, 0.f } });
	renderer->drawSprite(tile, { { 10.f, 0.f, 0.f } });
	renderer->drawSprite(tile, { { 20.f, 0.f, 0.f } });
	renderer->drawSprite(tile, { { 30.f, 0.f, 0.f } });
	renderer->drawSprite(tile, { { 40.f, 0.f, 0.f } });

	onEvent("mouse_click", TwoDE::Event(std::function([=, this](TwoDE::Input::MouseEventInfo& params)
		{
			if (params.button == TwoDE::Input::MOUSE_BUTTON::LEFT_BUTTON)
			{
				TWODE_INFO("Mouse x position: {}", params.position.x);
				TWODE_INFO("Mouse y position: {}", params.position.x);
				dragging = true;
			}
			if (params.button == TwoDE::Input::MOUSE_BUTTON::RIGHT_BUTTON)
			{
				auto& transform = getEntityRegistry()->get<TwoDE::Transform>(player);
				transform.rotate(-1);
			}
		}
	)));

	onEvent("mouse_release", TwoDE::Event(std::function([=, this](TwoDE::Input::MouseEventInfo& params)
		{
			if (params.button == TwoDE::Input::MOUSE_BUTTON::LEFT_BUTTON)
				dragging = false;
		}
	)));

	onEvent("mouse_scroll", TwoDE::Event(std::function([=, this](TwoDE::Input::ScrollEventInfo& params)
		{
			glm::vec3 scale = glm::vec3{ params.offset.y, params.offset.x, 0.0f };

			auto& cam = getEntityRegistry()->get<TwoDE::Transform>(camera);

			cam.scale(scale*TwoDE::EngineTime::deltaTime * 4.0f);
		}
	)));
}

void SandboxApp::update()
{
	TwoDE::Application::update();

	glm::vec2 right{ 1, 0 };
	glm::vec2 up{ 0, 1 };

	TwoDE::Input input = TwoDE::Locator::getLocator().getInputSystem();

	auto& transform= getEntityRegistry()->get<TwoDE::Transform>(player);

	if (input.buttonPressed(TwoDE::Input::BUTTON::RIGHT_KEY))
	{
		transform.translate(right * (speed * TwoDE::EngineTime::deltaTime));
	}
	if (input.buttonPressed(TwoDE::Input::BUTTON::LEFT_KEY))
	{
		transform.translate(right * (-1 * speed * TwoDE::EngineTime::deltaTime));
	}
	if (input.buttonPressed(TwoDE::Input::BUTTON::UP_KEY))
	{
		transform.translate(up * (speed * TwoDE::EngineTime::deltaTime));
	}
	if (input.buttonPressed(TwoDE::Input::BUTTON::DOWN_KEY))
	{
		transform.translate(up * (-1 * speed * TwoDE::EngineTime::deltaTime));
	}

	auto registry = getEntityRegistry();
	
	if (dragging)
	{
		glm::vec2 position = TwoDE::Locator::getLocator().getInputSystem().getCursorPosition() - glm::vec2{ 0.5f, 0.5f };

		auto& cam = registry->get<TwoDE::Transform>(camera);

		cam.translate(position * -1.f * TwoDE::EngineTime::deltaTime * 50.f);
	}

	renderer->clear(TwoDE::Color(0.2f, 0.4f, 0.6f, 1.0f));
}