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

#ifndef ENTER_NUMBER_COMMAND_H
#define ENTER_NUMBER_COMMAND_H
#include"Command.h"
namespace client
{
    class EnterNumberCommand : public Command
    {
    public:
        explicit EnterNumberCommand(double d);
        ~EnterNumberCommand();
        explicit EnterNumberCommand(const EnterNumberCommand& d);

	private:

		 void executeImpl()noexcept override;
		 void undoImpl()noexcept override;
		 EnterNumberCommand* cloneImpl()const override;
		 const char* getHelpMessageImpl()const noexcept override;

        EnterNumberCommand(EnterNumberCommand&&) = delete;
        EnterNumberCommand& operator=(const EnterNumberCommand&) = delete;
        EnterNumberCommand& operator=(EnterNumberCommand&&) = delete;

        double m_top;
    };

}
#endif // !ENTER_NUMBER_COMMAND_H


