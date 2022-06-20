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

using std::unordered_map;

namespace ramba 
{
    class Publisher::PublisherImpl
    {
    public:
        PublisherImpl() = default;
        ~PublisherImpl() = default;

        void subscribe(const string& eventName, unique_ptr<Observer> observer);
        void unsubscribe(const string& eventName, const string& observerName);
        void notify(const string& eventName, shared_ptr<Event>event);     // push semantic
    private:
        using Observers = unordered_map<string, unique_ptr<Observer>>;
        using Events = unordered_map<string, Observers>;

        Events m_events;
    };

    void Publisher::PublisherImpl::subscribe(const std::string& eventName, std::unique_ptr<Observer> observer)
    {
    }

    void Publisher::PublisherImpl::unsubscribe(const string& eventName, const string& observerName)
    {
    }

    void Publisher::PublisherImpl::notify(const string& eventName, shared_ptr<Event> event)
    {
    }

    void Publisher::unsubscribe(const std::string& eventName, const std::string& observerName)
    {
    }

    void Publisher::notify(const std::string& eventName, std::shared_ptr<Event> event)
    {
    }

}
