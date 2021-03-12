#include "PubSub.h"
#include "Event.h"

namespace TwoDE
{
	void PubSub::subscribe(std::string topic, Event event)
	{
		if (subscriptions.find(topic) == subscriptions.end())
		{
			subscriptions[topic] = std::vector<Event>();
		}

		subscriptions[topic].push_back(event);
	}

	void TwoDE::PubSub::init()
	{
	}
}
