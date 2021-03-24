#pragma once

#include "../../src/TwoDE.h"
#include <memory>

class SandboxApp : public TwoDE::Application
{
	bool dragging = false;

	std::shared_ptr<TwoDE::Sprite> sprite;

	float speed = 10.0f;
public:
	void start() override;
	void update() override;
};

TwoDE::Application* TwoDE::createApplication()
{
	return new SandboxApp();
}
