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
#include <iostream>
#include"Cli.h"
#include"CommandDispatcher.h"
#include"StackUpdatedObserver.h"
#include"UserInputObserver.h"
#include"Stack.h"

using namespace std;
int main()
{
    std::cout << "Ramba  Copyright (C) 2022  Barth. Feudong\n"
        << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
        << "This is free software, and you are welcome to redistribute it\n"
        << "under certain conditions; type `show c' for details.\n\n";

    ui::Cli cli{ std::cin, std::cout };
    client::CommandDispatcher cd{ cli };

    cli.subscribe(ui::UserInterface::CommandEntered, make_unique<ui::UserInputObserver>(cd));

    service::Stack::getInstance().subscribe(service::Stack::stackChanged, make_unique<ui::StackUpdatedObserver>(cli));

    cli.execute();

    return 0;
}

