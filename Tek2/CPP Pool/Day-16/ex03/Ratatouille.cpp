/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** Ratatouille
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille()
{
}

Ratatouille::Ratatouille(Ratatouille const &other)
{
    this->_tmp.clear();
    this->_tmp << other._tmp.str();
}

Ratatouille &Ratatouille::operator=(const Ratatouille &other)
{
    this->_tmp.clear();
    this->_tmp << other._tmp.str();
    return *this;
}

Ratatouille::~Ratatouille()
{
}
