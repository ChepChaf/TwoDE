#pragma once

#include "../../src/TwoDE.h"
#include <memory>

class PrimitivesApp : public TwoDE::Application
{
	std::vector<std::shared_ptr<TwoDE::Sprite>> circles;
	std::vector<std::shared_ptr<TwoDE::Sprite>> squares;
	std::vector<std::shared_ptr<TwoDE::Sprite>> lines;
	bool dragging = false;
public:
	void start() override;
	void update() override;
};

TwoDE::Application* TwoDE::createApplication()
{
	return new PrimitivesApp();
}
