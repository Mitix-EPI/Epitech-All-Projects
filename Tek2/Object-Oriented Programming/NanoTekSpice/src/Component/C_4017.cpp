/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4017
*/

#include "Components.hpp"

C_4017::C_4017() : Component("4017")
{
    this->_pinMax = 16;
    this->_increment = 0;
    this->_metamorph = nts::Tristate::UNDEFINED;

    this->_map[1 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 5
    this->_map[2 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 1
    this->_map[3 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 0
    this->_map[4 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 2
    this->_map[5 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 6
    this->_map[6 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 7
    this->_map[7 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 3
    this->_map[9 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 8
    this->_map[10 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 4
    this->_map[11 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 9
    this->_map[12 - 1] = std::bind(&C_4017::computeOutput, this, std::placeholders::_1); // Output 0-5

    this->_map[13 - 1] = std::bind(&C_4017::computeInput, this, std::placeholders::_1); // Input
    this->_map[14 - 1] = std::bind(&C_4017::computeInput, this, std::placeholders::_1); // Clock
    this->_map[15 - 1] = std::bind(&C_4017::computeInput, this, std::placeholders::_1); // Reset

    this->_map[8 - 1] = std::bind(&C_4017::computeVSS, this, std::placeholders::_1); // VSS
    this->_map[16 - 1] = std::bind(&C_4017::computeVDD, this, std::placeholders::_1); // VDD
}

void C_4017::simulate(std::size_t pin)
{
    (void) pin;
    if (pin == 84) {
        this->_computed = false;
        return;
    }
    if (this->_computed)
        return;
    if (!this->_computed)
        this->_computed = true;
    this->_pin[12].component->simulate(this->_pin[12].index);
    this->_pin[13].component->simulate(this->_pin[13].index);
    this->_pin[14].component->simulate(this->_pin[14].index);
    nts::Tristate input = this->computeInput(12);
    nts::Tristate clock = this->computeInput(13);
    if (this->computeInput(14) == nts::Tristate::TRUE) {
        this->reset();
        return;
    }
    if (clock == nts::Tristate::TRUE && input == nts::Tristate::FALSE) {
        this->progress();
    }
    if (clock == nts::Tristate::UNDEFINED) {
        for (const auto &it : this->_possibleOutputsIndex) {
            this->_outputs[it] = nts::UNDEFINED;
        }
    }
}

void C_4017::progress(void)
{
    if (this->_increment > 8)
        this->_increment = 0;
    else if (this->computeInput(13) == nts::Tristate::TRUE) {
        this->_increment += 1;
    }
}

void C_4017::reset(void)
{
    this->_increment = 0;
}

nts::Tristate C_4017::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4017::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

nts::Tristate C_4017::computeOutput(std::size_t pin)
{
    nts::Tristate input = this->computeInput(12);
    nts::Tristate clock = this->computeInput(13);
    if (clock == nts::Tristate::UNDEFINED && this->computeInput(14) == nts::Tristate::UNDEFINED) {
        return nts::Tristate::UNDEFINED;
    }
    if (clock == nts::Tristate::UNDEFINED) {
        if (pin == 2 || pin == 11)
            return nts::Tristate::TRUE;
        return nts::Tristate::FALSE;
    }
    if (input == nts::Tristate::UNDEFINED && clock == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (this->computeInput(14) == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    if (clock == nts::Tristate::TRUE && (!input) == nts::Tristate::TRUE) {
        if (pin == 11) {
            if (this->_increment < 5)
                return nts::Tristate::TRUE;
            else
                return (nts::Tristate::FALSE);
        }
        if (pin == this->_possibleOutputsIndex[this->_increment] - 1) {
            return (nts::Tristate::TRUE);
        }
    }
    if (clock == nts::Tristate::TRUE && input == nts::Tristate::TRUE && this->computeInput(14) == nts::Tristate::FALSE) {
        if (pin == 11) {
            if (this->_increment < 5)
                return nts::Tristate::TRUE;
            else
                return (nts::Tristate::FALSE);
        }
        if (pin == this->_possibleOutputsIndex[this->_increment] - 1) {
            return (nts::Tristate::TRUE);
        }
    }
    if (clock == nts::Tristate::FALSE && this->_increment >= 5 && pin == 11)
        return nts::Tristate::FALSE;
    if (clock == nts::Tristate::FALSE && input == nts::Tristate::FALSE && (pin == 11 || pin == this->_possibleOutputsIndex[this->_increment] - 1))
        return nts::Tristate::TRUE;
    return (nts::Tristate::FALSE);
}

nts::Tristate C_4017::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4017::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C_4017::dump(void) const
{
    std::cout << "4017" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4017::~C_4017()
{
}
