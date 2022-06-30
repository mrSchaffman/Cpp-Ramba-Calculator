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

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include<vector>
#include<string>
#include<istream>

namespace utility
{
    class Tokenizer
    {
    public:
        using Token = std::string;
        using Tokens = std::vector<std::string>;
        using const_iterator = Tokens::const_iterator;

        // small trick
        const_iterator begin()const { return m_tokens.cbegin(); };
        const_iterator end()const { return m_tokens.cend(); };

        explicit Tokenizer(const std::string& userInput);
        explicit Tokenizer(std::istream& inStream);
        const Token& operator[](size_t index) { return m_tokens[index]; }
        ~Tokenizer() = default;

    private:
        void tokenize(std::istream&);

        Tokenizer() = delete;
        Tokenizer(const Tokenizer&) = delete;
        Tokenizer(Tokenizer&&) = delete;
        Tokenizer& operator=(const Tokenizer&) = delete;
        Tokenizer& operator=(Tokenizer&&) = delete;

        Tokens m_tokens;
    };

}
#endif // !TOKENIZER_H


