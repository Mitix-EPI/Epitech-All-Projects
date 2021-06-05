/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4069
*/

#include "Components.hpp"

C_4069::C_4069() : Component("4069")
{
    this->_pinMax = 14;

    this->_map[1 - 1] = std::bind(&C_4069::computeInput, this, std::placeholders::_1); // Input
    this->_map[2 - 1] = std::bind(&C_4069::computeOutput, this, std::placeholders::_1); // Output

    this->_map[3 - 1] = std::bind(&C_4069::computeInput, this, std::placeholders::_1); // Input
    this->_map[4 - 1] = std::bind(&C_4069::computeOutput, this, std::placeholders::_1); // Output
    
    this->_map[5 - 1] = std::bind(&C_4069::computeInput, this, std::placeholders::_1); // Input
    this->_map[6 - 1] = std::bind(&C_4069::computeOutput, this, std::placeholders::_1); // Output
    
    this->_map[9 - 1] = std::bind(&C_4069::computeInput, this, std::placeholders::_1); // Input
    this->_map[8 - 1] = std::bind(&C_4069::computeOutput, this, std::placeholders::_1); // Output
    
    this->_map[11 - 1] = std::bind(&C_4069::computeInput, this, std::placeholders::_1); // Input
    this->_map[10 - 1] = std::bind(&C_4069::computeOutput, this, std::placeholders::_1); // Output
    
    this->_map[13 - 1] = std::bind(&C_4069::computeInput, this, std::placeholders::_1); // Input
    this->_map[12 - 1] = std::bind(&C_4069::computeOutput, this, std::placeholders::_1); // Output

    this->_map[7 - 1] = std::bind(&C_4069::computeVSS, this, std::placeholders::_1); // VSS
    this->_map[14 - 1] = std::bind(&C_4069::computeVDD, this, std::placeholders::_1); // VDD
}

void C_4069::simulate(std::size_t pin)
{
    if (pin > this->_pinMax || pin <= 1) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    pin--;
    if (pin == 1) {
        this->_pin[0].component->simulate(this->_pin[0].index);
    } else if (pin == 3) {
        this->_pin[2].component->simulate(this->_pin[2].index);
    } else if (pin == 5) {
        this->_pin[4].component->simulate(this->_pin[4].index);
    } else if (pin == 7) {
        this->_pin[8].component->simulate(this->_pin[8].index);
    } else if (pin == 9) {
        this->_pin[10].component->simulate(this->_pin[10].index);
    } else if (pin == 11) {
        this->_pin[12].component->simulate(this->_pin[12].index);
    }
}

nts::Tristate C_4069::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4069::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

nts::Tristate C_4069::convertCalc(nts::Tristate status) const
{
    Logical<int> logical;
    if (status == nts::Tristate::UNDEFINED)
        return status;
    else
        return convertIntToTristate(logical.NOT(convertTristateToInt(status)));
}

nts::Tristate C_4069::computeOutput(std::size_t pin) const
{
    if (pin == 1) {
        return this->convertCalc(this->computeInput(0));
    } else if (pin == 3) {
        return this->convertCalc(this->computeInput(2));
    } else if (pin == 5) {
        return this->convertCalc(this->computeInput(4));
    } else if (pin == 7) {
        return this->convertCalc(this->computeInput(8));
    } else if (pin == 9) {
        return this->convertCalc(this->computeInput(10));
    } else if (pin == 11) {
        return this->convertCalc(this->computeInput(12));
    }
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4069::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4069::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    if (pin == 7) {
        throw VSSSet("Can't set VSS pin.", 22);
    }
    if (pin == 14) {
        throw VDDSet("Can't set VDD pin", 23);
    }
    this->_pin[pin - 1].component = &other;
    this->_pin[pin - 1].index = otherPin;
}

void C_4069::dump(void) const
{
    std::cout << "4081int" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4069::~C_4069()
{
}
