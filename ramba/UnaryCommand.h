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

#ifndef UNARY_COMMAND_H
#define UNARY_COMMAND_H


#include"Command.h"

namespace client
{
	class UnaryCommand : public Command
	{
	public:
		virtual ~UnaryCommand() = default;

	protected:
		virtual void checkPreconditionsImpl() override;
		UnaryCommand() = default;
		UnaryCommand(const UnaryCommand&);

	private:
		// inherited from the base class Command
		virtual void executeImpl()noexcept override;
		virtual void undoImpl()noexcept override;
		virtual Command* cloneImpl()const override;
		virtual const char* getHelpMessageImpl() const noexcept override;

		// specific to a unary operation
		virtual double unaryOperation(double)const noexcept = 0;
		double m_top;
	};

}
#endif // !UNARY_COMMAND_H


