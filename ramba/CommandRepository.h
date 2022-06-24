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

#ifndef COMMAND_REPOSITORY_H
#define COMMAND_REPOSITORY_H
#include<memory>
#include<string>
#include<unordered_map>

#include"Command.h"

namespace client
{
    // the prototype registry class
    class CommandRepository
    {
    public:
        std::unique_ptr<Command> getCommandByName(const std::string& commandName) const;
        void addCommand(const std::string& commandName, std::unique_ptr<Command>cmd);

        static CommandRepository& getInstance();
    private:
        CommandRepository();
        ~CommandRepository();

        class CommandRepositoryImpl;
        std::unique_ptr<CommandRepositoryImpl> impl;
        using Commands = std::unordered_map<std::string, std::unique_ptr<Command>>;
        Commands m_commands;

    private:
        CommandRepository(const CommandRepository&) = delete;
        CommandRepository(CommandRepository&&) = delete;
        CommandRepository& operator=(const CommandRepository&) = delete;
        CommandRepository& operator=(CommandRepository&&) = delete;
    };

}
#endif // !COMMAND_REPOSITORY_H


