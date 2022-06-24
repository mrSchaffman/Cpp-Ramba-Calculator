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
	class Command
	{
	public:
		virtual ~Command() = default;
		void execute();
		void undo();
		Command*clone()const;
		const char* getHelpMessage() const;
		// delete commands for plugings...
		virtual deallocate();
	
	protected:
		Command() = default;
		Command(const Command&) = default;

	private:
		virtual void checkPreconditionsImpl();

		virtual void executeImpl() = 0;
		virtual void undoImpl() = 0;
		virtual Command* cloneImpl()const = 0;
		virtual const char* getHelpMessageImpl() const = 0;

		Command(Command&&) = delete;
		Command& operator=(const Command&) = delete;
		Command& operator=(Command&&) = delete;
	};

}

#endif // !COMMAND_H



