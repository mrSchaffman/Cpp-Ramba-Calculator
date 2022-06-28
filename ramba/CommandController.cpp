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

#include "CommandController.h"
#include"CommandCoordinator.h"

namespace client
{
    class CommandController::CommandControllerImpl
    {
    public:
        CommandControllerImpl();
        ~CommandControllerImpl();
        void processCommand(const std::string& eventName, std::unique_ptr<Command> c);

    private:
    };

    CommandController::CommandController(service::CommandCoordinator& c) : m_coordonator{c}
    {
    }

    CommandController::~CommandController()
    {
    }

    void CommandController::processCommand(const std::string& eventName, std::unique_ptr<Command> c)
    {
        impl->processCommand(eventName, std::move(c));
    }

    CommandController::CommandControllerImpl::CommandControllerImpl()
    {
    }

    CommandController::CommandControllerImpl::~CommandControllerImpl()
    {
    }

    void CommandController::CommandControllerImpl::processCommand(const std::string& commandName, std::unique_ptr<Command> c)
    {
        /*
        * 1 - Command entered -> change state
        * 2 - display wait commandDispatcher->displayWait();
          3 - transfer command to CommandManager to execute.
        */
        //m_commandCoordinator.executeCommand(commandName, std::move(c));
    }

}

//void client::commandcontroller::changestate(std::unique_ptr<calculatorstatemachine> st)
//{
//}
