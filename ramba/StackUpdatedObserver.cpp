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

#include "StackUpdatedObserver.h"

namespace ui
{
    StackUpdatedObserver::StackUpdatedObserver(UserInterface& ui): Observer("stackChanged"),m_ui(ui)
    {
    }

    void StackUpdatedObserver::notifyImpl(std::shared_ptr<utility::Event> ev)
    {
        //auto data = std::dynamic_pointer_cast<StackEvent>(ev);
        //if (data)
        //    m_cd.stackChanged(data->getElements(4,vector<double>...));  // retrive the n elements coming from the stack
        //else
        //    throw utility::Exception("Unable to convert Event to UIEvent!");
        //return;

        m_ui.stackChanged();
    }

}
