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

#include<string>
#include "CommandDispatcher.h"
#include"CommandController.h"
#include"Exception.h"

namespace client
{
	class CommandDispatcher::CommandDispatcherImpl
	{
	public:
		explicit CommandDispatcherImpl(ui::UserInterface& ui);

		void executeCommand(const std::string& command);


	private:
		bool isNum(const std::string&, double& d);
		void handleCommand(std::unique_ptr<client::Command> command); // to update with string
		void printHelp() const;

		CommandController m_controller;
		ui::UserInterface& m_ui;

	};

	CommandDispatcher::CommandDispatcher(ui::UserInterface& userI)
	{
		pimpl = std::make_unique<CommandDispatcherImpl>(userI);
	}

	CommandDispatcher::~CommandDispatcher()
	{

	}

	void CommandDispatcher::commandEntered(const std::string & command)
	{
		pimpl->executeCommand(command);
	}

	CommandDispatcher::CommandDispatcherImpl::CommandDispatcherImpl(ui::UserInterface & ui):m_ui(ui)
	{
	}

	void CommandDispatcher::CommandDispatcherImpl::executeCommand(const std::string & command)
	{
		// to do
	}

	bool CommandDispatcher::CommandDispatcherImpl::isNum(const std::string & a, double & d)
	{
		return false;
	}

	void CommandDispatcher::CommandDispatcherImpl::handleCommand(std::unique_ptr<client::Command> command)
	{
		try
		{
			m_controller.processCommand("command",std::move(command));
		}
		catch (utility::Exception& e)
		{
			//m_ui.postMessage(e.what());
		}
	}

	void CommandDispatcher::CommandDispatcherImpl::printHelp() const
	{
		// to do
	}

}