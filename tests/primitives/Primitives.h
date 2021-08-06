#pragma once

#include <TwoDE.h>
#include <memory>

class PrimitivesApp : public TwoDE::Application
{
	std::vector<TwoDE::Entity> circles;
	std::vector<TwoDE::Entity> squares;
	std::vector<TwoDE::Entity> lines;
	bool dragging = false;
public:
	void start() override;
	void update() override;
};

TwoDE::Application* TwoDE::createApplication()
{
	return new PrimitivesApp();
}
