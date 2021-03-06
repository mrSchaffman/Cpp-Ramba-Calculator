#pragma once
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

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include"Event.h"
#include"Observer.h"
using std::string;
using std::unique_ptr;
using std::shared_ptr;

namespace utility
{
    class Publisher
    {
    public:
        void subscribe(const string& eventName, unique_ptr<Observer> observer);
        void unsubscribe(const string& eventName, const string& observerName);

    protected:
        Publisher();
        ~Publisher();
        void notify(const string& eventName, shared_ptr<Event>event)const;     // push semantic
		void registerEvent(const std::string&);

    private:
        class PublisherImpl;
        std::unique_ptr<PublisherImpl> publisherImpl;   // Bridge design pattern
    };


}


#endif // !Publisher_h

