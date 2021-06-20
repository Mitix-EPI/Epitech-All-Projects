/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <iostream>
#include <stack>

class Parser {
    public:
        Parser();
        ~Parser();

        void feed(const std::string &);
        int result() const { return this->_res; };
        void reset() { this->_res = 0; };

        int _res;
        std::stack<int> tmp;
    protected:
    private:
};

#endif /* !PARSER_HPP_ */
