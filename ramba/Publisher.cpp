/*
    Copyright (C) 2022  Barth.Feudong
    Author can be contacted here: <https://github.com/mrSchaffman/Cpp-Ramba-Calculator>

    This file is part of the Ramba Command Line Calculator project.

    ramba is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ramba is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/


#include "Publisher.h"
#include<unordered_map>
#include<memory>
#include<sstream>
#include"Exception.h"
#include<algorithm>

using std::unordered_map;

namespace utility
{
    class Publisher::PublisherImpl
    {
    public:
		using ObserverName = const std::string;
		using EventName = const std::string;

        PublisherImpl() = default;
        ~PublisherImpl() = default;

        void subscribe(EventName& eventName, unique_ptr<Observer> observer);
        void unsubscribe(EventName& eventName, ObserverName& observerName);
        void notify(EventName& eventName, shared_ptr<Event>event);     // push semantic
    private:

        using ObserversByEvent = unordered_map<ObserverName, unique_ptr<Observer>>;
        using Observers = unordered_map<EventName, ObserversByEvent>;

		Observers m_observers;
    };

    void Publisher::PublisherImpl::subscribe(EventName& eventName, std::unique_ptr<Observer> observer)
    {
		auto ptr = m_observers.find(eventName);
		if (ptr == std::end(m_observers))
		{
			std::ostringstream oss;
			oss << "Event with name '" << eventName << "' not supported";
			throw Exception(oss.str());

		}
		else
		{
			auto iter = m_observers[eventName].insert(std::make_pair(observer->getName(), std::move(observer)));
			if (!iter.second)
			{
				std::ostringstream oss;
				oss << "Observer '" << observer->getName() << "' is already registered";
				throw Exception(oss.str());

			}
				
		}
    }

    void Publisher::PublisherImpl::unsubscribe(EventName& eventName, ObserverName& observerName)
    {
		auto count = m_observers.count(eventName);
		if (count)
		{
			auto found = m_observers[eventName].erase(observerName);
			if (!found)
			{
				std::ostringstream oss;
				oss << "Observer '" << observerName << "' not found registered";
				throw Exception(oss.str());

			}
		}
		else
		{
			std::ostringstream oss;
			oss << "Event with name '" << eventName << "' not supported";
			throw Exception(oss.str());

		}
    }

    void Publisher::PublisherImpl::notify(EventName& eventName, shared_ptr<Event> event_)
    {
		auto ptr = m_observers.find(eventName);
		if (ptr != std::end(m_observers))
			std::for_each(std::begin(ptr->second), std::end(ptr->second), [](auto & observer) { observer.second->notify(event_); });
		else
		{
			std::ostringstream oss;
			oss << "Event with name '" << eventName << "' not supported";
			throw Exception(oss.str());

		}

    }
	void Publisher::subscribe(const string& eventName, unique_ptr<Observer> observer)
	{
		publisherImpl->subscribe(eventName, std::move(observer));
	}

    void Publisher::unsubscribe(const std::string& eventName, const std::string& observerName)
    {
		publisherImpl->unsubscribe(eventName, observerName);

    }

    void Publisher::notify(const std::string& eventName, std::shared_ptr<Event> event)
    {
		publisherImpl->notify(eventName, event);

    }

}
