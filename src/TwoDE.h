#pragma once

#include "Core.h"
#include "Logger.h"

#include "Application.h"

#include "ResourceManager.h"
#include "EngineTime.h"

#include "Event.h"

#include "Locator.h"
#include "Scene.h"

#include "Systems/ISystem.h"

#define onEvent(...) TwoDE::Locator::getLocator().getEventSystem().subscribe(__VA_ARGS__)

#include "Input.h"
#include "PubSub.h"

#include "EngineMath.h"
#include "Random.h"
// Entrypoint
#include "Entrypoint.h"

