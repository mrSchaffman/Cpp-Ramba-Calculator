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

#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include"Handler.h"
#include"Command.h"

namespace service
{
    // The Base class for the Command handlers
    class CommandManager : public utility::Handler
    {
    public:
        explicit CommandManager(std::shared_ptr<client::Command> cmd): m_cmd{cmd}{}
        virtual ~CommandManager() = default;

    protected:
        std::shared_ptr<utility::Handler> m_nextHandler;
        std::shared_ptr<client::Command> m_cmd;
    private:
        virtual void setNextHandlerImpl(std::shared_ptr<Handler> s) noexcept override;
        virtual void handleImpl()noexcept override;

        //CommandManager(): utility::Handler(){}
    };
}
#endif // !COMMAND_MANAGER_H


