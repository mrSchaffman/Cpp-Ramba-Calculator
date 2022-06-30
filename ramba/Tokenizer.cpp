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

#include "Tokenizer.h"
#include<algorithm>
#include<sstream>
namespace utility
{
    Tokenizer::Tokenizer(const std::string& userInput)
    {
        std::istringstream is{ userInput };
        tokenize(is);
    }
    Tokenizer::Tokenizer(std::istream& inStream) // std::cin
    {
        tokenize(inStream);
    }
    void Tokenizer::tokenize(std::istream& is)
    {
        m_tokens.assign(std::istream_iterator<std::string>{is},
            std::istream_iterator < std::string>{});
        for (auto& s : m_tokens)
        {
            // transform each char from each string.
            std::transform(s.begin(), s.end(),s.begin(), ::tolower);
        }
    }
}