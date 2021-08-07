#pragma once

#include "../../src/TwoDE.h"
#include <memory>

class SandboxApp : public TwoDE::Application
{
	bool dragging = false;

	TwoDE::Entity player;

	float speed = 1.0f;
public:
	void start() override;
	void update() override;
};

TwoDE::Application* TwoDE::createApplication()
{
	return new SandboxApp();
}
