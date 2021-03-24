#pragma once
#include "TwoDE.h"

#include "Window.h"
#include "Renderer.h"

#include <iostream>

extern TwoDE::Application* TwoDE::createApplication();

int main(int argc, char** argv)
{
    auto app = TwoDE::createApplication();

    app->init();
    app->start();

    while(!app->shouldClose())
        app->update();

    delete app;
}