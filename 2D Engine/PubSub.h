#pragma once

#include "Event.h"

#include <functional>
#include <string>
#include <map>
#include <vector>

namespace TwoDE
{
	class TWO_DLL PubSub
	{
		std::map<std::string, std::vector<Event>> subscriptions;
	public:
		void publish(std::string topic);
		void subscribe(std::string topic, Event event);
		void init();
	};
}

