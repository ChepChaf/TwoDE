#pragma once

#include "Core.h"

#include <functional>
#include <any>

namespace TwoDE
{	
	class TWO_DLL Event
	{
		template<typename T>
		using callback = std::function<void(T&)>;
		
		std::any fun;

	public:
		template<typename T>
		Event(callback<T> fun) : fun(fun) {}
		
		template<typename T>
		void call(T params)
		{
			std::any_cast<callback<T>>(fun)(params);
		}
	};
}