/*
** EPITECH PROJECT, 2021
** exceptions.hpp
** File description:
** exceptions.hpp
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <iostream>
#include <exception>

class Errors : public std::exception
{
    public:
        Errors(std::string const &message = "");
        ~Errors();

        const char *what(void) const noexcept;
    private:
        std::string _message;
    protected:
};

#endif /* !EXCEPTIONS_HPP_ */
