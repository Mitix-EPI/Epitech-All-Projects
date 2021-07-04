/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <iostream>
#include <string>

class Error: public std::exception {
    public:
        Error(std::ostream &stream, const std::string &message) throw();
        virtual ~Error(void) throw();

        const char *what(void) const throw();

    protected:
        std::ostream &_stream;
        std::string _message;
    private:
};

#endif /* !ERROR_HPP_ */
