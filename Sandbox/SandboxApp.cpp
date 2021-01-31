#include "SandboxApp.h"

#include <iostream>

void SandboxApp::update()
{
	TwoDE::Application::update();
	std::cout << "Hello, from SandboxApp" << std::endl;
}