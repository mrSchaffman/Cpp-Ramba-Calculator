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

#include "Stack.h"

using namespace utility;

using namespace Service
{
    Stack& Stack::getInstance()
    {
        // TODO: insert return statement here
    }

    void Stack::push(double, bool suppressChangeEvent)
    {
    }

    double Stack::pop(bool suppressChangeEvent) const
    {
        return 0.0;
    }

    void Stack::getElements(size_t, std::vector<double>&) const
    {
    }

    std::vector<double> Stack::getElements(size_t) const
    {
        return std::vector<double>();
    }

    size_t Stack::size() const
    {
        return size_t();
    }

    void Stack::clear() const
    {
    }

}
