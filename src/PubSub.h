#pragma once

#include "Core.h"
#include "Event.h"

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <any>

namespace TwoDE
{
	class TWO_DLL PubSub
	{
		std::unordered_map<std::string, std::vector<Event>> subscriptions;
	public:
		template<typename T>
		void publish(std::string topic, T& params)
		{
			if (subscriptions.find(topic) != subscriptions.end())
			{
				for (auto event : subscriptions[topic])
				{
					event.call(params);
				}
			}
		}

		void subscribe(std::string topic, Event event);
		void init();
	};
}

