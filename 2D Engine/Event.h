#pragma once

#include "Core.h"

#include <functional>

namespace TwoDE
{
	class TWO_DLL Event
	{
		std::function<void()> fun;
	public:
		Event(std::function<void()> fun) : fun(fun) {}
		const void call() const;
	};
}