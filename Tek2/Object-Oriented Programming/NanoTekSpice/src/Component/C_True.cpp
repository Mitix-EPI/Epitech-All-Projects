/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_True
*/

#include "Components.hpp"

C_True::C_True() : Component("true")
{
    this->_status = nts::Tristate::TRUE;
    this->_pinMax = 1;
}

void C_True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    this->_pin[pin - 1].component = &other;
    this->_pin[pin - 1].index = otherPin;
    other.setLink(otherPin, *this, pin);
}

nts::Tristate C_True::compute(std::size_t pin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return nts::Tristate::TRUE;
}

void C_True::dump(void) const
{
    std::cout << this->_type << " state: 1" << std::endl;
}

C_True::~C_True()
{
}
