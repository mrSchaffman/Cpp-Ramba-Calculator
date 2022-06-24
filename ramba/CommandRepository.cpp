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

#include "CommandRepository.h"
#include<sstream>
#include"Exception.h"

using namespace utility;

namespace client
{

    class CommandRepository::CommandRepositoryImpl
    {
    public:
        CommandRepositoryImpl() = default;
        std::unique_ptr<Command> getCommandByName(const std::string& commandName) const;
        void addCommand(const std::string& commandName, std::unique_ptr<Command>cmd);

    private:
        using Commands = std::unordered_map<std::string, std::unique_ptr<Command>>;
        Commands m_commands;

    };



    std::unique_ptr<Command> CommandRepository::getCommandByName(const std::string& commandName) const
    {
        return  impl->getCommandByName(commandName);
    }

    void CommandRepository::addCommand(const std::string& commandName, std::unique_ptr<Command> cmd)
    {
        impl->addCommand(commandName, std::move(cmd));
    }

    CommandRepository& CommandRepository::getInstance()
    {
        static CommandRepository instance;
        return instance;
    }

    CommandRepository::CommandRepository() : impl{new CommandRepositoryImpl}
    {
    }
    CommandRepository::~CommandRepository()
    {
    }

    std::unique_ptr<Command> CommandRepository::CommandRepositoryImpl::getCommandByName(const std::string& commandName) const
    {
        const auto& pr = m_commands.find(commandName);
        if (pr != std::end(m_commands))
            return std::unique_ptr<Command>((pr->second)->clone());
        else
            return nullptr;      // to verify.
    }

    void CommandRepository::CommandRepositoryImpl::addCommand(const std::string& commandName, std::unique_ptr<Command> cmd)
    {
        auto pr = m_commands.emplace(commandName, std::move(cmd));
        if (!pr.second)
        {
            std::ostringstream oss;
            oss << "The Command " << commandName << " is already registered!";
            throw Exception(oss.str());
        }
    }

}
