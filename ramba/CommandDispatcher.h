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
#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H
#include"UserInterface.h"
#include<memory>

namespace client
{
    class CommandDispatcher
    {
    public:

		explicit CommandDispatcher(ui::UserInterface& userI);
		~CommandDispatcher();
		void commandEntered(const std::string& command);

    private:
        CommandDispatcher() = default;
		CommandDispatcher(const CommandDispatcher&) = delete;
		CommandDispatcher(CommandDispatcher&&) = delete;
		CommandDispatcher& operator=(const CommandDispatcher&) = delete;
		CommandDispatcher& operator=(CommandDispatcher&&) = delete;

		class CommandDispatcherImpl;
		std::unique_ptr<CommandDispatcherImpl> pimpl;
    };

}

#endif // !COMMAND_DISPATCHER_H


