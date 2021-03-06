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
#ifndef ENTER_NUMBER_COMMAND_MANAGER_H
#define ENTER_NUMBER_COMMAND_MANAGER_H
#include"CommandManager.h"
#include"EnterNumberCommand.h"
#include<memory>

namespace service
{
    class EnterNumberCommandManager : public CommandManager
    {
    public:
        EnterNumberCommandManager(std::shared_ptr<client::Command> numberCmd): CommandManager(numberCmd){}
		//void handle() override;
		~EnterNumberCommandManager() = default;
    private:
        void handleImpl()noexcept override;

        EnterNumberCommandManager(const EnterNumberCommandManager&) = delete;
    };
}
#endif // !ENTER_NUMBER_COMMAND_MANAGER_H


