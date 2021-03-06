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
#ifndef BINARY_COMMAND_H
#define BINARY_COMMAND_H


#include"Command.h"

namespace client
{
	// second prototype hierarchy
	class BinaryCommand : public Command
	{
	public:
		virtual ~BinaryCommand() = default;

	protected:
		virtual void checkPreconditionsImpl() const override;

		BinaryCommand() = default;
		BinaryCommand(const BinaryCommand&);

	private:
		BinaryCommand(BinaryCommand&&) = delete;
		BinaryCommand& operator=(const BinaryCommand&) = delete;
		BinaryCommand& operator=(BinaryCommand&&) = delete;

		void executeImpl() noexcept override;
		// and 		virtual const char* getHelpMessageImpl()noexcept const = 0; from the base class. it doesn't make sence to implement it here.

		void undoImpl() noexcept override;
		virtual double binaryOperation(double next, double top) const noexcept = 0;
		// 
		double m_top;
		double m_next;
	};

}
#endif // BINARY_COMMAND_H


