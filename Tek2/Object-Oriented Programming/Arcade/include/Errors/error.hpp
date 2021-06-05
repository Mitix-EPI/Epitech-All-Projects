/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>
#include <string>

class error: public std::exception {
    public:
        error(std::ostream &stream, const std::string &message) throw();
        virtual ~error(void) throw();

        const char *what(void) const throw();

    protected:
        std::ostream &_stream;
        std::string _message;
    private:
};

#endif /* !ERROR_HPP_ */
