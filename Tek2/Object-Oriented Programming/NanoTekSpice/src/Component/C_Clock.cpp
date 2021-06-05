/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_Clock
*/

#include "Components.hpp"

C_Clock::C_Clock() : Component("clock")
{
    this->_pinMax = 1;
}

void C_Clock::switchValue(void)
{
    if (this->_status == nts::Tristate::TRUE) {
        this->_status = nts::Tristate::FALSE;
    } else if (this->_status == nts::Tristate::FALSE) {
        this->_status = nts::Tristate::TRUE;
    }
}

void C_Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 2 && otherPin == 100) {
        this->_pin[2].component = &other;
        this->_pin[2].index = 1;
        return;
    }
    if (pin == 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    this->_pin[0].component = &other;
    this->_pin[0].index = otherPin;
}

void C_Clock::simulate(std::size_t pin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    if (this->_pin[0].component == nullptr) {
        throw InvalidPin("This pin is NULL", 19);
    }
    this->_pin[2].component->simulate(this->_pin[2].index);
    this->_status = this->_pin[2].component->compute(this->_pin[2].index);
}

nts::Tristate C_Clock::compute(std::size_t pin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return this->_status;
}

void C_Clock::dump(void) const
{
    std::string status = "U";
    if (this->_status == nts::Tristate::TRUE) {
        status = "1";
    } else if (this->_status == nts::Tristate::FALSE) {
        status = "0";
    }
    std::cout << this->_type << " state: " << status << std::endl;
}

C_Clock::~C_Clock()
{
}
