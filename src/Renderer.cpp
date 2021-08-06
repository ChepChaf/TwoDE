#include "Renderer.h"

#include "OpenGLRenderer.h"

namespace TwoDE
{
	Renderer* Renderer::createRenderer()
	{
		return new OpenGLRenderer();
	}
}