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

#include<deque>
#include"Stack.h"
#include"Exception.h"
#include"StackEvent.h"
#include<algorithm>
#include<iterator>


namespace service
{
	const std::string Stack::stackChanged = "stackChanged";
	const std::string Stack::stackError = "error";
	
	class Stack::StackImpl
	{
	public:
		explicit StackImpl(const Stack& p):parent(p){}
		void push(double, bool suppressChangeEvent = false);
		double pop(bool suppressChangeEvent = false);
		
		void getElements(size_t, std::vector<double>&)const;
		std::vector<double> getElements(size_t)const;

		void swapTop();
		void dropTop();
		void duplicateTop();
		void negateTop();
		double top() const;

		size_t size()const;
		void clear();

	private:
		std::deque<double> stack;
		const Stack& parent;	// keep reference for the original to be able to raising event,
	};


	void Stack::StackImpl::push(double d, bool suppressChangeEvent)
	{
		stack.push_back(d);
		if (!suppressChangeEvent) parent.notify(Stack::stackChanged, nullptr);
		return;
	}

	double Stack::StackImpl::pop(bool suppressChangeEvent)
	{
		if (!stack.empty())		// precondition use case drop
		{
			auto val = stack.back();
			stack.pop_back();

			if (!suppressChangeEvent) parent.notify(Stack::stackChanged, nullptr);
			return val;
		}
		else                  // alternative sequence use case drop
		{
			parent.notify(Stack::stackError, std::make_shared<StackEvent>(StackEvent::ErrorType::EMPTY));
			throw Exception(StackEvent::getMessage(StackEvent::ErrorType::EMPTY));

		}
		
	}

	void Stack::StackImpl::swapTop()
	{
		if (stack.size() > 2)	// precondition use case swap
		{
			auto first = stack.back();
			stack.pop_back();
			auto second = stack.back();
			stack.pop_back();

			stack.push_back(first);
			stack.push_back(second);

			// raise the stackChanged Event.
			parent.notify(Stack::stackChanged, nullptr);
		}
		else					// alternative sequence use case swap
		{
			parent.notify(Stack::stackError, std::make_shared<StackEvent>(StackEvent::ErrorType::FEW_ARGUMENT));
			throw Exception(StackEvent::getMessage(StackEvent::ErrorType::FEW_ARGUMENT));

		}
	}

	void Stack::StackImpl::getElements(size_t s, std::vector<double>& v)const
	{
		if(stack.size() > s)
		std::copy_n(std::rbegin(stack), s, std::back_inserter(v));
		return;
	}

	std::vector<double> Stack::StackImpl::getElements(size_t s)const
	{
		std::vector<double> result;
		getElements(s, result);

		return result;
	}
	size_t Stack::StackImpl::size()const
	{
		return stack.size();
	}
	void Stack::StackImpl::clear()
	{
		stack.clear();
		
		// raise the stackChanged event and notify.
		parent.notify(Stack::stackChanged, nullptr);
		return;
	}
	
	void Stack::StackImpl::dropTop()
	{

	}
	void Stack::StackImpl::duplicateTop()
	{

	}
	void Stack::StackImpl::negateTop()
	{

	}

	double Stack::StackImpl::top()const
	{
		return stack.back();

	}


    Stack& Stack::getInstance()
    {
		static Stack instance;
		return instance;
    }

    void Stack::push(double d, bool suppressChangeEvent)
    {
		stackImpl->push(d, suppressChangeEvent);
    }

    double Stack::pop(bool suppressChangeEvent) 
    {
        return stackImpl->pop(suppressChangeEvent);
    }

    void Stack::getElements(size_t s, std::vector<double>& v) const
    {
		stackImpl->getElements(s, v);
		return;
    }

    std::vector<double> Stack::getElements(size_t s) const
    {
        return stackImpl->getElements(s);
    }

	void Stack::negateTop()
	{
		stackImpl->negateTop();

	}

	double Stack::top() const
	{
		return 	stackImpl->top();

	}

	void Stack::swapTop()
	{
		stackImpl->swapTop();
		return;
	}

	void Stack::dropTop()
	{
		stackImpl->dropTop();

	}

	void Stack::duplicateTop()
	{
		stackImpl->duplicateTop();

	}

    size_t Stack::size() const
    {
        return stackImpl->size();
		
    }

    void Stack::clear() 
    {
		stackImpl->clear();

    }

	Stack::Stack()
	{
		stackImpl = std::make_unique<StackImpl>(*this);

		Publisher::registerEvent(stackChanged);
		Publisher::registerEvent(stackError);
	}

}
