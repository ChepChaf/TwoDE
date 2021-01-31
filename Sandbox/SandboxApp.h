#pragma once

#include "TwoDE.h"

class SandboxApp : public TwoDE::Application
{
public:
	void update() override;
};

TwoDE::Application* TwoDE::createApplication()
{
	return new SandboxApp();
}
