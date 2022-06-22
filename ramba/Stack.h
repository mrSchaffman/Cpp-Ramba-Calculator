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
#ifndef STACK_H
#define STACK_H

#include<string>
#include<memory>
#include<vector>
#include"Publisher.h"

namespace ramba
{
    class Stack : private Publisher
    {
    public:
        static Stack& getInstance();
        void push(double, bool suppressChangeEvent = false);
        double pop(bool suppressChangeEvent = false);
        void getElements(size_t, std::vector<double>&)const;
        std::vector<double> getElements(size_t)const;
		
		/*
			swap the top element from the stack
			Precondition: stack has at least 2 elements
			Alternative Sequence: precondition false -> error message
			Postcondition: The top 2 elements from the stack was swaped.
		*/
		void swapTop();
		void dropTop();
		void duplicateTop();
		void negateTop();
		double top()const;

        using Publisher::subscribe;
        using Publisher::unsubscribe;

        size_t size()const;
        void clear() ;

		// Event Type raise by this Stack.
		static const std::string stackChanged;
		static const std::string stackError;

    private:
        Stack();
        ~Stack() = default;

        Stack(const Stack&) = delete;
        Stack(Stack&&) = delete;
        Stack& operator=(const Stack&) = delete;
        Stack& operator=(Stack&&) = delete;
        
        class StackImpl;
        std::unique_ptr<StackImpl> stackImpl;
    };

}
#endif // !STACK_H

