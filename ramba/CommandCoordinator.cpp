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

#include"CommandCoordinator.h"
#include"EnterNumberCommandManager.h"
#include"CommandManager.h"
#include"CommandLogManager.h"
#include"UndoStack.h"
#include"RedoStack.h"

namespace service
{

    class CommandCoordinator::CommandCoordinatorImpl
    {
    public:
        CommandCoordinatorImpl();
        ~CommandCoordinatorImpl() = default;
        void executeCommand(const std::string& commandName, std::unique_ptr<client::Command> cmd);

    private:
    };

    CommandCoordinator::CommandCoordinator() : impl{new CommandCoordinatorImpl}
    {
		
    }

    CommandCoordinator::~CommandCoordinator()
    {
    }

    void CommandCoordinator::executeCommand(const std::string& commandName, std::unique_ptr<client::Command> cmd)
    {
        impl->executeCommand(commandName, std::move(cmd));
    }

    CommandCoordinator::CommandCoordinatorImpl::CommandCoordinatorImpl()
    {
    }

    void CommandCoordinator::CommandCoordinatorImpl::executeCommand(const std::string& commandName, std::unique_ptr<client::Command> cmd)
    {
		std::shared_ptr<client::Command> shared = std::move(cmd);
		std::unique_ptr<CommandLogManager> cmdLog = std::make_unique<CommandLogManager>(shared);
		std::unique_ptr<EnterNumberCommandManager> enterCmdManager = std::make_unique<EnterNumberCommandManager>(shared);
		//std::unique_ptr<AdditionCommandManager> addCmdManager = std::make_unique<AdditionCommandManager>(shared);
		
		//std::unique_ptr<CommandManager> root = std::make_shared(new CommandManager(shared));

		//If(EnterNumberCommandManager)
		//{
		//	root->setNextHandler(enterCmdManager);
		//}
		//If(AdditionCommandManager)
		//{
		//	root->setNextHandler(addCmdManager);
		//}
		
		//	root->setNextHandler(cmdLog);
		//	root->handle();

        // to do
    }

}
