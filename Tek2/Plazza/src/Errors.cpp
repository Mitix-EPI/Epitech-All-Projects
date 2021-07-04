/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** Errors
*/

#include "Errors.hpp"

Error::Error(std::ostream &stream, const std::string &message) throw() : _stream(stream), _message(message)
{
}

Error::~Error()
{
}

const char *Error::what(void) const throw()
{
    return _message.c_str();
}