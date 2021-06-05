/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4030
*/

#include "Components.hpp"

C_4030::C_4030() : Component("4030")
{
    this->_pinMax = 14;

    this->_map[1 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input
    this->_map[2 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input
    this->_map[3 - 1] = std::bind(&C_4030::computeOutput, this, std::placeholders::_1); // Output

    this->_map[4 - 1] = std::bind(&C_4030::computeOutput, this, std::placeholders::_1); // Output
    this->_map[5 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input
    this->_map[6 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input

    this->_map[7 - 1] = std::bind(&C_4030::computeVSS, this, std::placeholders::_1); // VSS

    this->_map[8 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input
    this->_map[9 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input
    this->_map[10 - 1] = std::bind(&C_4030::computeOutput, this, std::placeholders::_1); // Output

    this->_map[11 - 1] = std::bind(&C_4030::computeOutput, this, std::placeholders::_1); // Output
    this->_map[12 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input
    this->_map[13 - 1] = std::bind(&C_4030::computeInput, this, std::placeholders::_1); // Input

    this->_map[14 - 1] = std::bind(&C_4030::computeVDD, this, std::placeholders::_1); // VDD
}

void C_4030::simulate(std::size_t pin)
{
    pin--;
    if (pin == 2) {
        this->_pin[0].component->simulate(this->_pin[0].index);
        this->_pin[1].component->simulate(this->_pin[1].index);
    } else if (pin == 3) {
        this->_pin[4].component->simulate(this->_pin[4].index);
        this->_pin[5].component->simulate(this->_pin[5].index);
    } else if (pin == 9) {
        this->_pin[7].component->simulate(this->_pin[7].index);
        this->_pin[8].component->simulate(this->_pin[8].index);
    } else if (pin == 10) {
        this->_pin[11].component->simulate(this->_pin[11].index);
        this->_pin[12].component->simulate(this->_pin[12].index);
    }
}

nts::Tristate C_4030::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4030::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

nts::Tristate C_4030::convertCalc(std::size_t pin1, std::size_t pin2) const
{
    Logical<int> logical;
    const int int_pin1 = convertTristateToInt(this->computeInput(pin1));
    const int int_pin2 = convertTristateToInt(this->computeInput(pin2));

    if (int_pin1 == -1 && int_pin2 == -1) {
        return nts::Tristate::UNDEFINED;
    }
    return (convertIntToTristate(logical.XOR(int_pin1, int_pin2)));
}

nts::Tristate C_4030::computeOutput(std::size_t pin) const
{
    if (pin == 2) {
        return this->convertCalc(0, 1);
    } else if (pin == 3) {
        return this->convertCalc(4, 5);
    } else if (pin == 9) {
        return this->convertCalc(7, 8);
    } else if (pin == 10) {
        return this->convertCalc(11, 12);
    }
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4030::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4030::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C_4030::dump(void) const
{
    std::cout << "4030" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4030::~C_4030()
{
}
