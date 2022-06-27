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

#include "CommandManager.h"

namespace service
{
	CommandManager::CommandManager(std::shared_ptr<client::Command> cmd): m_cmd{std::move(cmd)}
	{
		//m_cmd = std::move(cmd);
	}
	void CommandManager::setNextHandler(std::shared_ptr<Handler> s)
	{
		if (m_nextHandler) m_nextHandler->setNextHandler(s);
		else m_nextHandler = s;
	}
	void CommandManager::handle()
	{
		if (m_nextHandler)m_nextHandler->handle();
	}
}
