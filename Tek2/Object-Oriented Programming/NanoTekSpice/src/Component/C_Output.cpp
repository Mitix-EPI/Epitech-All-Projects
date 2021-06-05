/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_Output
*/

#include "Components.hpp"

C_Output::C_Output() : Component("output")
{
    this->setPinMax(1);
}

void C_Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    this->_pin[pin - 1].component = &other;
    this->_pin[pin - 1].index = otherPin;
}

void C_Output::simulate(std::size_t pin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    if (this->_pin[0].component == nullptr) {
        throw InvalidPin("This pin is NULL", 19);
    }
    this->_pin[0].component->simulate(this->_pin[0].index);
    this->_status = this->_pin[0].component->compute(this->_pin[0].index);
}

nts::Tristate C_Output::compute(std::size_t pin)
{
    if (pin != 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    if (this->_pin[0].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[0].component->compute(this->_pin[0].index);
}

void C_Output::dump(void) const
{
    std::string status = "U";
    if (this->_status == nts::Tristate::TRUE) {
        status = "1";
    } else if (this->_status == nts::Tristate::FALSE) {
        status = "0";
    }
    std::cout << this->_type << " state: " << status << std::endl;
}

C_Output::~C_Output()
{
}
