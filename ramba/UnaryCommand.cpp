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

#include "UnaryCommand.h"
#include"Exception.h"
#include"Stack.h"

namespace client
{
	void UnaryCommand::checkPreconditionsImpl()
	{
		// precondition specify in the use case description
		if (service::Stack::getInstance().size() < 1)
			throw Exception("The Stack must have at least one element.");			// alternative sequence describe in the use case.
	}
	UnaryCommand::UnaryCommand(const UnaryCommand & rhs) : Command(rhs), m_top{ rhs.m_top }
	{
	}
	void UnaryCommand::executeImpl() noexcept
	{
		/*
			The unaryCommandManager class is not yet implemented.
			1- The unaryCommandManager requests (pop) the top element from the stack
			2- The Stack respond to the request with the top element.
			3- The unaryCommandManager execute the unary Operation with the retrieved top element
			4- The unarayCommandManager send a push request to the stack with the result of the operation
			5- The Stack push the result and raise the Event: stackChange(), because it'is enabled to false.
		*/
		m_top = service::Stack::getInstance().pop(false);
		service::Stack::getInstance().push(unaryOperation(m_top, false));
	}
	void UnaryCommand::undoImpl() noexcept
	{
		/*
			1- The unaryCommandManager send a request to pop the top element to the Stack
			2- The Stack remove the top element
			3- The unaryCommandManager send a request to push the value keep by the UnaryCommand.
		*/
		service::Stack::getInstance().pop(false);
		service::Stack::getInstance().push(m_top);
	}
	Command * UnaryCommand::cloneImpl() const
	{
		return nullptr;
	}
}
