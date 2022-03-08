/*
** EPITECH PROJECT, 2021
** exceptions.cpp
** File description:
** exceptions.cpp
*/

#include "commons/exceptions.hpp"

Errors::Errors(std::string const &message): _message(message)
{
}

Errors::~Errors()
{
}

const char *Errors::what(void) const noexcept
{
    return (_message.c_str());
}