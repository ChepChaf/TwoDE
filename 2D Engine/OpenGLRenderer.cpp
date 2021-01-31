#include "OpenGLRenderer.h"

#include "glad/glad.h"

namespace TwoDE
{
	OpenGLRenderer::OpenGLRenderer()
	{
	}
	OpenGLRenderer::~OpenGLRenderer()
	{
	}
	void OpenGLRenderer::drawSprite(Sprite& sprite)
	{
	}

	int OpenGLRenderer::init(int width, int height)
	{
		// TODO: Find way to abstract this so it's not dependent on glfw
		if (!gladLoadGL())
			return -1;

		glViewport(0, 0, width, height);

		return 0;
	}

	void OpenGLRenderer::clear(Color clearColor)
	{
		glClearColor(clearColor.r(), clearColor.g(), clearColor.b(), clearColor.alpha());
		glClear(GL_COLOR_BUFFER_BIT);
	}
}