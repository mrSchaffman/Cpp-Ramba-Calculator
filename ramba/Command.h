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
#ifndef COMMAND_H
#define COMMAND_H

namespace client
{
	/*
		This class in a prototype -> (prototype design pattern).
	*/

	/*
		Commands supported
		_________________________________________________
		Command				UnaryCommand	BinaryCommand
		_________________________________________________
		EnterCommand		Sine			Add
		SwapTopOfStack		Cosine			Subtract
		DropTopOfStack		Tangent			Multiply
		Duplicate			Arcsine			Divide
		ClearStack			Arccosine		Power
							Arctangent		Root
							Negate
		_________________________________________________
	
		Defining the public interface for a class via a mixture of public nonvirtual functions
		and private virtual functions is a design principle known as the non-virtual interface
		(NVI) pattern. The NVI pattern states that polymorphic interfaces should always be
		defined using non-virtual public functions that forward calls to private virtual functions.

		This Base Class is implementated as a prototype, as in the prototype design pattern.
	*/
	class Command
	{
	public:
		virtual ~Command() = default;
		void execute();
		void undo();
		Command*clone()const;
		const char* getHelpMessage() const;
		// delete commands for plugings...
		virtual void deallocate();
	
	protected:
		Command() = default;
		Command(const Command&) = default;
		virtual void checkPreconditionsImpl()const;

	private:

		virtual void executeImpl()noexcept = 0;
		virtual void undoImpl()noexcept = 0;
		virtual Command* cloneImpl()const = 0;
		virtual const char* getHelpMessageImpl()const noexcept  = 0;

		Command(Command&&) = delete;
		Command& operator=(const Command&) = delete;
		Command& operator=(Command&&) = delete;
	};
}

#endif // !COMMAND_H



