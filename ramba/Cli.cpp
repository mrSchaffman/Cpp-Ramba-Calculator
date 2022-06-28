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

#include "Cli.h"
namespace ui
{
	class Cli::CliImpl
	{
	public:

		CliImpl(Cli& cli, std::istream& in, std::ostream& out);
		~CliImpl();

		void executeImpl(bool suppressStartupMessage = false, bool echo = false);
		void inputUserMessageImpl(const std::string& msg);
		void stackChangedImpl();

	private:
		void startUpMessage();
		Cli& m_parent;
		std::istream& m_in;
		std::ostream& m_out;


	};

	Cli::Cli(std::istream & in, std::ostream & out) //: pimpl{new CliImpl(in,out)}
	{
		pimpl = std::make_unique<CliImpl>(*this, in, out);
	}

	Cli::~Cli()
	{
	}
	void Cli::execute(bool suppressStartupMessage, bool echo)
	{
		pimpl->executeImpl(suppressStartupMessage, echo);
	}
	void Cli::inputUserMessage(const std::string& msg)
    {
		pimpl->inputUserMessageImpl(msg);
    }
    void Cli::stackChanged()
    {
		pimpl->stackChangedImpl();
    }
	Cli::CliImpl::CliImpl(Cli& cli, std::istream & in, std::ostream & out): m_parent(cli),m_in(in),m_out(out)
	{
	}
	Cli::CliImpl::~CliImpl()
	{
	}
	void Cli::CliImpl::executeImpl(bool suppressStartupMessage, bool echo)
	{
		// to do
	}
	void Cli::CliImpl::inputUserMessageImpl(const std::string & msg)
	{
		// to do
	}
	void Cli::CliImpl::stackChangedImpl()
	{
		// to do
	}
	void Cli::CliImpl::startUpMessage()
	{
		// to do
	}
}