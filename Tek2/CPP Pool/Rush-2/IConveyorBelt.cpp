/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** IConveyorBelt
*/

#include "IConveyorBelt.hpp"

IConveyorBelt::IConveyorBelt()
{
}

IConveyorBelt::~IConveyorBelt()
{
    if (this->_object != nullptr)
        delete this->_object;
}
