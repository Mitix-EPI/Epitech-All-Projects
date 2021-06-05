/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4008
*/

#include "Components.hpp"

C_4008::C_4008() : Component("4008")
{
    this->_pinMax = 16;

    this->_map[1 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input
    this->_map[15 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input

    this->_map[2 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input
    this->_map[3 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input

    this->_map[4 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input
    this->_map[5 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input

    this->_map[6 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input
    this->_map[7 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Input

    this->_map[9 - 1] = std::bind(&C_4008::computeInput, this, std::placeholders::_1); // Carry In

    this->_map[10 - 1] = std::bind(&C_4008::computeOutput, this, std::placeholders::_1); // Output
    this->_map[11 - 1] = std::bind(&C_4008::computeOutput, this, std::placeholders::_1); // Output
    this->_map[12 - 1] = std::bind(&C_4008::computeOutput, this, std::placeholders::_1); // Output
    this->_map[13 - 1] = std::bind(&C_4008::computeOutput, this, std::placeholders::_1); // Output

    this->_map[14 - 1] = std::bind(&C_4008::computeOutput, this, std::placeholders::_1); // Carry Out

    this->_map[8 - 1] = std::bind(&C_4008::computeVSS, this, std::placeholders::_1); // VSS
    this->_map[16 - 1] = std::bind(&C_4008::computeVDD, this, std::placeholders::_1); // VDD
}

void C_4008::simulate(std::size_t pin)
{
    pin--;
    if (pin == 9) {
        this->_pin[5].component->simulate(this->_pin[5].index);
        this->_pin[6].component->simulate(this->_pin[6].index);
    } else if (pin == 10) {
        this->_pin[3].component->simulate(this->_pin[3].index);
        this->_pin[4].component->simulate(this->_pin[4].index);
    } else if (pin == 11) {
        this->_pin[1].component->simulate(this->_pin[1].index);
        this->_pin[2].component->simulate(this->_pin[2].index);
    } else if (pin == 12) {
        this->_pin[0].component->simulate(this->_pin[0].index);
        this->_pin[14].component->simulate(this->_pin[14].index);
    } else if (pin == 13) {
        this->_pin[8].component->simulate(this->_pin[8].index);
    }
}

nts::Tristate C_4008::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18, "Set link pin: " + std::to_string(pin));
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4008::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

nts::Tristate C_4008::convertCalc(std::size_t pin1, std::size_t pin2) const
{
    const int int_pin1 = convertTristateToInt(this->computeInput(pin1));
    const int int_pin2 = convertTristateToInt(this->computeInput(pin2));

    if (int_pin1 == int_pin2 && int_pin1 == -1)
        return nts::Tristate::UNDEFINED;
    if ((int_pin1 && int_pin2) && (int_pin1 == -1 || int_pin2 == -1))
        return nts::Tristate::UNDEFINED;
    return (convertIntToTristate(int_pin1 && int_pin2));
}

nts::Tristate C_4008::returnBit(std::size_t pin1, std::size_t pin2, std::size_t pin3, bool carryIn)
{
    this->_A = this->_pin[pin1].component->compute(this->_pin[pin1].index);
    this->_B = this->_pin[pin2].component->compute(this->_pin[pin2].index);
    if (carryIn)
        this->_CarryIn = this->_pin[pin3].component->compute(this->_pin[pin3].index);

    return convertIntToTristate(!(this->_A && this->_B) && (this->_A || this->_B));
}

bool C_4008::isUndefined(std::size_t pin) const
{
    if (pin == 9) {
        nts::Tristate first = this->_pin[5].component->compute(this->_pin[5].index);
        nts::Tristate second = this->_pin[6].component->compute(this->_pin[6].index);

        if (first == nts::Tristate::UNDEFINED && second == nts::Tristate::UNDEFINED)
            return true;
    } else if (pin == 10) {
        nts::Tristate first = this->_pin[3].component->compute(this->_pin[3].index);
        nts::Tristate second = this->_pin[4].component->compute(this->_pin[4].index);

        if (first == nts::Tristate::UNDEFINED && second == nts::Tristate::UNDEFINED)
            return true;
    } else if (pin == 11) {
        nts::Tristate first = this->_pin[1].component->compute(this->_pin[1].index);
        nts::Tristate second = this->_pin[2].component->compute(this->_pin[2].index);

        if (first == nts::Tristate::UNDEFINED && second == nts::Tristate::UNDEFINED)
            return true;
    } else if (pin == 12) {
        nts::Tristate first = this->_pin[0].component->compute(this->_pin[0].index);
        nts::Tristate second = this->_pin[14].component->compute(this->_pin[14].index);

        if (first == nts::Tristate::UNDEFINED && second == nts::Tristate::UNDEFINED)
            return true;
    } else if (pin == 13) {
        nts::Tristate first = this->_pin[8].component->compute(this->_pin[13].index);

        if (first == nts::Tristate::UNDEFINED)
            return true;
    }
    return false;
}

nts::Tristate C_4008::computeOutput(std::size_t pin)
{
    nts::Tristate xOR = this->returnBit(5, 6, 8, true);

    if (this->isUndefined(pin))
        return nts::Tristate::UNDEFINED;
    if (pin == 9)
        return (convertIntToTristate((xOR || this->_CarryIn) && !(xOR && _CarryIn)));

    this->_CarryIn = convertIntToTristate((this->_A && this->_B) || (this->_B && this->_CarryIn) || (this->_A && this->_CarryIn));
    xOR = this->returnBit(3, 4, 0, false);
    if (pin == 10)
        return (convertIntToTristate((xOR || this->_CarryIn) && !(xOR && _CarryIn)));

    this->_CarryIn = convertIntToTristate((this->_A && this->_B) || (this->_B && this->_CarryIn) || (this->_A && this->_CarryIn));
    xOR = this->returnBit(1, 2, 0, false);
    if (pin == 11)
        return (convertIntToTristate((xOR || this->_CarryIn) && !(xOR && _CarryIn)));

    this->_CarryIn = convertIntToTristate((this->_A && this->_B) || (this->_B && this->_CarryIn) || (this->_A && this->_CarryIn));
    xOR = this->returnBit(14, 0, 0, false);
    if (pin == 12)
        return (convertIntToTristate((xOR || this->_CarryIn) && !(xOR && _CarryIn)));
    return convertIntToTristate((this->_A && this->_B) || (this->_B && this->_CarryIn) || (this->_A && this->_CarryIn));
    // return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4008::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4008::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    if (pin == 8) {
        throw VSSSet("Can't set VSS pin.", 22);
    }
    if (pin == 16) {
        throw VDDSet("Can't set VDD pin", 23);
    }
    this->_pin[pin - 1].component = &other;
    this->_pin[pin - 1].index = otherPin;
}

void C_4008::dump(void) const
{
    std::cout << "4008" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4008::~C_4008()
{
}
