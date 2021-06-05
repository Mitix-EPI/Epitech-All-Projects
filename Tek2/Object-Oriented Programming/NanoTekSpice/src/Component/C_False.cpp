/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_False
*/

#include "Components.hpp"

C_False::C_False() : Component("false")
{
    this->_status = nts::Tristate::FALSE;
    this->_pinMax = 1;
}

void C_False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    this->_pin[pin - 1].component = &other;
    this->_pin[pin - 1].index = otherPin;
    other.setLink(otherPin, *this, pin);
}

nts::Tristate C_False::compute(std::size_t pin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return nts::Tristate::FALSE;
}

void C_False::dump(void) const
{
    std::string status = "U";
    if (this->_status == nts::Tristate::TRUE) {
        status = "1";
    } else if (this->_status == nts::Tristate::FALSE) {
        status = "0";
    }
    std::cout << this->_type << " state: 0" << std::endl;
}

C_False::~C_False()
{
}
