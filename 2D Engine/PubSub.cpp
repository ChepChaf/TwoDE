#include "PubSub.h"
#include "Event.h"

void TwoDE::PubSub::publish(std::string topic)
{
	if (subscriptions.find(topic) != subscriptions.end())
	{
		for (auto& event : subscriptions[topic])
		{
			event.call();
		}
	}
}

void TwoDE::PubSub::subscribe(std::string topic, Event event)
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
