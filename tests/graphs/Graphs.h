#pragma once

#include <TwoDE.h>
#include <memory>

class GraphsApp : public TwoDE::Application
{
public:
	void start() override;
	void update() override;
};

TwoDE::Application* TwoDE::createApplication()
{
	return new GraphsApp();
}
