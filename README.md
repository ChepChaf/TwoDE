# TwoD Engine

Disclaimer: This is an educational project, I'm working on it with the intention of learning how game engines work,
it probably won't be usable on a productive environment.

## Planned functionality:
- [ ] Full 2D renderer with GLSL support
- [ ] Support for some AI algorithms:
	- [ ] FSM
	- [ ] Planning
	- [ ] Pathfinding
	- [ ] Behaviour Trees
- [ ] Lua Scripting
- [ ] ECS system

## Dependencies:
	- glew
	- GLFW
	- spdlog

## Building:
- Windows:
	TBD
- Linux & MacOS
	- mkdir build && cd build
	- cmake "Unix Makefiles" ..
	- make
## Usage:

### Basic structure
```
// Include TwoDE Header.
#include "TwoDE.h"

// Create class inheriting from TwoDE::Application
class MyApp : public TwoDE::Application
{
	public:
	// override start and update
	void start() override;
	void update() override;
}

```

### Loading sprites
```
...
// Read file from disk and save it in the ResourceManager
player = TwoDE::Locator::getLocator().getSceneManagerSystem().CreateEntity();
renderer->drawSprite(player, TwoDE::Sprite("resources/sprites/Character01.png"), TwoDE::Vector3{ 0.0f, 0.0f, 1.0f });
```

### events
```
onEvent("mouse_click", TwoDE::Event(std::function([=](TwoDE::Input::MouseEventInfo& params)
	{
		if (params.button == TwoDE::Input::MOUSE_BUTTON::LEFT_BUTTON)
		{
			// Log to console
			TWODE_INFO("Mouse x position: {}", params.position.getX());
			TWODE_INFO("Mouse y position: {}", params.position.getY());
		}
		if (params.button == TwoDE::Input::MOUSE_BUTTON::RIGHT_BUTTON)
		{
			// Get Transform component and rotate
			auto& transform = getEntityRegistry()->get<TwoDE::Transform>(player);
			transform.rotate(-1);
		}
	}
)));
```

### Draw 2D Primitives
```
...
// Lines
// origin - end - color - width
auto line = renderer->drawLine(Vector3{ 0.f, 0.f, 0.f }, Vector3{ 100.f, 100.f, 0.f }, Color{ 0.2f, 0.8f, 0.2f, 1.0f }, 1);

// Rects
// origin (lower-left corner) - size - color
auto rect = renderer->drawRect({ 0.f, 0.f, 0.f }, { 10.f, 10.f }, { 0.6f, 0.2f, 0.2f, 1.0f });

// Circles
// center - radius - color
auto cirle = renderer->drawCircle({ 0.f, 0.f, 0.f }, 50.f, { 0.2f, 0.2f, 0.6f, 1.0f });
```

### [More examples](../master/tests)
