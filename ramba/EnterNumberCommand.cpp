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

#include "EnterNumberCommand.h"
#include"Stack.h"
namespace client
{
    EnterNumberCommand::EnterNumberCommand(double d) : m_top{d}
    {
    }
    EnterNumberCommand::~EnterNumberCommand()
    {
    }
    EnterNumberCommand::EnterNumberCommand(const EnterNumberCommand& d):m_top{d.m_top}
    {
    }
    void EnterNumberCommand::executeImpl() noexcept
    {
        service::Stack::getInstance().push(m_top);
    }
    void EnterNumberCommand::undoImpl() noexcept
    {
        service::Stack::getInstance().pop();
    }
    EnterNumberCommand* EnterNumberCommand::cloneImpl() const
    {
        return new EnterNumberCommand{ *this };
    }
    const char* EnterNumberCommand::getHelpMessageImpl() const noexcept
    {
        return "Add number to the Stack";
    }
}

