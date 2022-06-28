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

#ifndef CLI_H
#define CLI_H
#include"UserInterface.h"
#include<istream>
#include<ostream>
namespace ui
{
    /*
        The Concrete Command Line Interface class

        Requirements on this class

    */
    class Cli : public UserInterface
    {
	public:

		Cli(std::istream& in, std::ostream& out);
		~Cli();

		// if echo = true -> each command is repeated before displaying the result.
		void execute(bool suppressStartupMessage = false, bool echo = false);
    private:
        void inputUserMessage(const std::string& msg)override;
        void stackChanged()override;

		class CliImpl;
		std::unique_ptr<CliImpl> pimpl;
    };

}
#endif // !CLI_H


