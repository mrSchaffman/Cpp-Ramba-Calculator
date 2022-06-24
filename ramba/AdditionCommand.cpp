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

#include "AdditionCommand.h"
namespace client
{
	AdditionCommand::AdditionCommand(const AdditionCommand & rhs):BinaryCommand{rhs}
	{
	}
	AdditionCommand * AdditionCommand::cloneImpl() const
	{
		return new AdditionCommand{*this};
	}
	double AdditionCommand::binaryOperation(double d1, double d2) const noexcept
	{
		return d1 + d2;
	}
	const char * AdditionCommand::getHelpMessageImpl() const noexcept
	{
		return "Replace the first two element on the Stack by the Sum of the two";
	}
}