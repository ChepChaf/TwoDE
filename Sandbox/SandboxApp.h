#pragma once

#include "TwoDE.h"
#include <memory>

class SandboxApp : public TwoDE::Application
{
	std::shared_ptr<TwoDE::Sprite> sprite;

	float speed = 1.0f;
public:
	void start() override;
	void update() override;
};

TwoDE::Application* TwoDE::createApplication()
{
	return new SandboxApp();
}
