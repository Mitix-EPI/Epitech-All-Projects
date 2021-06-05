/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Component
*/

#include "Component.hpp"

Component::Component(std::string type)
{
    this->setType(type);
}

Component::~Component()
{
}

int convertTristateToInt(nts::Tristate state)
{
    return state;
}

nts::Tristate convertIntToTristate(int state)
{
    if (state == 1)
        return nts::Tristate::TRUE;
    if (state == 0)
        return nts::Tristate::FALSE;
    return nts::Tristate::UNDEFINED;
}
