/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-tekspice-cyril.grosjean
** File description:
** C_InputTmp
*/

#include "Components.hpp"

C_InputTmp::C_InputTmp() : Component("inputtmp")
{
    this->setPinMax(1);
}

void C_InputTmp::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    this->_pin[0].component = &other;
    this->_pin[0].index = otherPin;
}

void C_InputTmp::switchValue(void)
{
    if (this->_status == nts::Tristate::TRUE) {
        this->_status = nts::Tristate::FALSE;
    } else if (this->_status == nts::Tristate::FALSE) {
        this->_status = nts::Tristate::TRUE;
    }
}

void C_InputTmp::simulate(std::size_t tick)
{
    (void) tick;
}

void C_InputTmp::dump(void) const
{
    std::cout << "InputTmp : " << this->_status << std::endl;
}

nts::Tristate C_InputTmp::compute(std::size_t pin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return this->_status;
}

C_InputTmp::~C_InputTmp()
{
}
