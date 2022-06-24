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

#include "BinaryCommand.h"
#include"Exception.h"
#include"Stack.h"

using namespace service;
using namespace utility;
namespace client
{
	void BinaryCommand::checkPreconditionsImpl() const
	{
		// precondition specify in the use case description
		if (service::Stack::getInstance().size() < 2)
			throw Exception("The Stack must have at least two elements.");			// alternative sequence describe in the use case.

	}

	BinaryCommand::BinaryCommand(const BinaryCommand & rhs): Command(rhs),m_top{rhs.m_top},m_next{rhs.m_next}
	{
	}

	void BinaryCommand::executeImpl() noexcept
	{
		m_top = service::Stack::getInstance().pop(false);
		m_next = service::Stack::getInstance().pop(false);
		service::Stack::getInstance().push(binaryOperation(m_top, m_next), false);

	}

	void BinaryCommand::undoImpl() noexcept
	{
		service::Stack::getInstance().pop(false);
		service::Stack::getInstance().push(m_next, false);
		service::Stack::getInstance().push(m_top, false);

	}

}

