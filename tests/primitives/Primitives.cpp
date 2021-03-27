#include "Primitives.h"

#include <iostream>

void PrimitivesApp::start()
{
	TWODE_INFO("Hello from PrimitivesApp");

	for (float i = -10; i < 0; i++)
	{
		float size = i * -1.f * 10.f;
		float center = (100.f - size) / 2;
		squares.push_back(renderer->drawRect({ center, center, i }, { size, size }, { 0.1f * -i, 0.2f, 0.2f, 1.0f }));
		renderer->drawCircle({ 50.f, 50.f, i }, size, { 0.2f, 0.2f, 0.1f * -i, 1.0f }, 1024.f);
	}

	for (float i = 0; i < 5; i++)
	{
		float size = 10.f - i;
		float center = 50.f;
		circles.push_back(renderer->drawCircle({ center, center, i }, size, { 0.2f, 0.2f, 0.2f * (i + 1), 1.0f }));
	}

	lines.push_back(renderer->drawLine({ 0.f, 0.f, 0.f }, { 100.f, 100.f, 0.f }, { 0.2f, 0.8f, 0.2f, 1.0f }, 1));
	lines.push_back(renderer->drawLine({ 100.f, 0.f, 0.f }, { 0.f, 100.f, 0.f }, { 0.2f, 0.8f, 0.2f, 1.0f }, 1));

	onEvent("mouse_click", TwoDE::Event(std::function([=](TwoDE::Input::MouseEventInfo& params)
		{
			if (params.button == TwoDE::Input::MOUSE_BUTTON::LEFT_BUTTON)
			{
				dragging = true;
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

			camera.get()->m_Transform.scale(scale * TwoDE::EngineTime::deltaTime * 4.0f);

			TWODE_INFO("Camera scaleX: {}", camera.get()->m_Transform.m_Scale.getX());
			TWODE_INFO("Camera scaleY: {}", camera.get()->m_Transform.m_Scale.getY());
		}
	)));
}

void PrimitivesApp::update()
{
	TwoDE::Application::update();

	if (dragging)
	{
		TwoDE::Vector2 position = TwoDE::Locator::getInputSystem().getCursorPosition() - TwoDE::Vector2{ 0.5f, 0.5f };

		camera.get()->m_Transform.translate(position * -1.f * TwoDE::EngineTime::deltaTime * 200.f);
	}

	for (int i = 0; i < circles.size(); i++)
	{
		circles[i]->getTransform()->rotate(20.f * TwoDE::EngineTime::deltaTime * (i % 2 == 0 ? -1 : 1));
	}

	for (int i = 0; i < squares.size(); i++)
	{
		squares[i]->getTransform()->rotate(20.f * TwoDE::EngineTime::deltaTime * (i % 2 == 0 ? -1 : 1));
	}

	for (int i = 0; i < lines.size(); i++)
	{
		lines[i]->getTransform()->rotate(20.f * TwoDE::EngineTime::deltaTime * (i % 2 == 0 ? -1 : 1));
	}

	renderer->clear({ 0.35f, 0.35f, 0.35f, 1.f });
}