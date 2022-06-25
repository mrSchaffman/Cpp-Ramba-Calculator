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
#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H
#include<memory>
#include"Stack.h"
#include"Command.h"
#include"UndoRedoStrategy.h"
#include<stack>
#include<vector>
#include<string>

namespace service
{
    // Entity Classes
    using UndoStack = std::stack<client::Command>;
    using RedoStack = std::stack<client::Command>;
    using CommandLog = std::vector<std::string>;

    // Business Logic class hierarchy
    class CommandManager
    {
    public:
        CommandManager();
        ~CommandManager();
        void executeCommand(std::unique_ptr<client::Command> cmd);

    private:
        class CommandManagerImpl;
        std::unique_ptr<CommandManagerImpl> impl;
    };

    class UndoCommandManager
    {
    public:
        UndoCommandManager()
        {
        }

        ~UndoCommandManager()
        {
        }
        void undo();

    private:

    };

    class RedoCommandManager
    {
    public:
        RedoCommandManager()
        {
        }

        ~RedoCommandManager()
        {
        }

        void redo();
    private:

    };

    class UninaryCommandManager
    {
    public:
        UninaryCommandManager()
        {
        }

        ~UninaryCommandManager()
        {
        }

    private:

    };

    class BinaryCommandManager
    {
    public:
        BinaryCommandManager()
        {
        }

        ~BinaryCommandManager()
        {
        }

    private:

    };




}
#endif // !COMMAND_MANAGER_H


