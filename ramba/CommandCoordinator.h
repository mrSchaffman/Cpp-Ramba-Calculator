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
#include"UndoStack.h"
#include"RedoStack.h"

namespace service
{

    class CommandCoordinator
    {
    public:
        CommandCoordinator() = default;
        ~CommandCoordinator();
        void executeCommand(const std::string& commandName, std::unique_ptr<client::Command> cmd);

    private:
        UndoStack ustack;
        RedoStack rstack;
    };

    // Command Manager hierarchy 
    // Business Logic class hierarchy

    class CommandManager
    {
    public:
        virtual ~CommandManager() = default;
        CommandManager(std::unique_ptr<client::Command>cmd) : m_cmd{ std::move(cmd) } {};
        virtual void execute() = 0;
    protected:
        std::unique_ptr<client::Command>m_cmd;
    private:
    };

    class UndoRedoCommandManager
    {
    public:
        UndoRedoCommandManager() = default;

        ~UndoRedoCommandManager() = default;
        void executeUndo();
        void executeRedo();
        size_t getUndoStackSize()const ;
        size_t getRedoStackSize()const ;

    private:

    };

}

#endif // !COMMAND_MANAGER_H


