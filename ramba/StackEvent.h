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

#ifndef STACKEVENT_H
#define STACKEVENT_H
#include"Event.h"   
#include<vector>


namespace service
{
    class StackEvent : public Event
    {
    public:
        enum class ErrorType
        {
            EMPTY,
            FEW_ARGUMENT,
        };

        StackEvent(ErrorType e) : err(e) {}
        StackEvent(const std::vector<double>& el) : mElement(el) { err = ErrorType::EMPTY; }

        static const char* getMessage(ErrorType);
        const char* getMessage()const;
        ErrorType getErrorType()const { return err; }
    private:
        ErrorType err;
        std::vector<double> mElement;

    };

}
#endif // !STACKEVENT_H


