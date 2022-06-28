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
#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H
#include"CalculatorStateMachine.h"
#include"CommandCoordinator.h"
#include<memory>
#include"Command.h"

namespace client
{
    // the context in the state design pattern
    // has direct link to the service side-> the CommandCoordonator
    class CommandController
    {        
    public:
        explicit CommandController(service::CommandCoordinator& c);
        CommandController() = default;

        ~CommandController();
        void processCommand(const std::string & commandName, std::unique_ptr<Command> c);
        //void changeState(std::unique_ptr<CalculatorStateMachine> st);
    private:
        //std::unique_ptr< CalculatorStateMachine> state;
        class CommandControllerImpl;
        std::unique_ptr< CommandControllerImpl> impl;
        service::CommandCoordinator& m_coordonator;
    private:

        CommandController(const CommandController&) = delete;
        CommandController(CommandController&&) = delete;
        CommandController& operator=(const CommandController&) = delete;
        CommandController& operator=(CommandController&&) = delete;
    };

}

#endif // !COMMAND_CONTROLLER_H



