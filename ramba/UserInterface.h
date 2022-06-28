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

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include"Publisher.h"
namespace ui
{
	/*
		 the UserInterface class itself is not the publisher. The UserInterface class is an abstract
		 interface for user interfaces in the system and is inheriting from the Publisher class
		 only to enforce the notion that user interfaces must implement the publisher interface
		 themselves. Both the CLI and the GUI classes will need to access public functions from
		 Publisher (for example, to raise events). Thus, the protected mode of inheritance is
		 appropriate in this instance.

		 So this class cannot be used as a publisher because of failing function not available
		 at protected level...

		 The UserInterface need to observer event coming from the stack
		 and the CommandDispatcher needs to observe event coming from the UserInterface
	*/

    class UserInterface : protected Publisher
    {
    public:
        UserInterface() = default;
        virtual~UserInterface() = default;

		// message comming from the user
		virtual void inputUserMessage(const std::string& msg) = 0;
		
		// message comming from the stack / the Model
		virtual void stackChanged() = 0;

		using Publisher::subscribe;
		using Publisher::unsubscribe;

		// The Name of the Command raised by the user Interface
		// and this is used to notify the observers along with the Data to be handle...
		// it is needed for attaching or detaching the Command
		// there is a need to define that Command.

		static const std::string CommandEntered;
    private:

    };

}
#endif // !USER_INTERFACE_H


