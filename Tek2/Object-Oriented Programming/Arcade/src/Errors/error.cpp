/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** error
*/

#include "Errors/error.hpp"

error::error(std::ostream &stream, const std::string &message) throw() : _stream(stream), _message(message)
{
}

error::~error()
{
}

const char *error::what(void) const throw()
{
    return _message.c_str();
}