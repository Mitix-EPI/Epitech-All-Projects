/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** C_4013
*/

#include "Components.hpp"

C_4013::C_4013(): Component("4013")
{
    this->_pinMax = 14;
    this->_Q1 = nts::Tristate::UNDEFINED;
    this->_Qb1 = nts::Tristate::UNDEFINED;
    this->_Q2 = nts::Tristate::UNDEFINED;
    this->_Qb2 = nts::Tristate::UNDEFINED;

    // FLIP FLOP 1

    this->_map[1 - 1] = std::bind(&C_4013::computeOutput, this, std::placeholders::_1); // Output 1 q
    this->_map[2 - 1] = std::bind(&C_4013::computeOutput, this, std::placeholders::_1); // Output 1 qB

    this->_map[3 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Clock 1

    this->_map[4 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Input 1 reset
    this->_map[5 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Input 1 data
    this->_map[6 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Input 1 set


    // // FLIP FLOP 2

    this->_map[8 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Input 2 set
    this->_map[9 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Input 2 data
    this->_map[10 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Input 2 reset

    this->_map[11 - 1] = std::bind(&C_4013::computeInput, this, std::placeholders::_1); // Clock 2

    this->_map[12 - 1] = std::bind(&C_4013::computeOutput, this, std::placeholders::_1); // Output 2 q
    this->_map[13 - 1] = std::bind(&C_4013::computeOutput, this, std::placeholders::_1); // Output 2 qB


    // // VSS VDD

    this->_map[7 - 1] = std::bind(&C_4013::computeVSS, this, std::placeholders::_1); // VSS
    this->_map[14 - 1] = std::bind(&C_4013::computeVDD, this, std::placeholders::_1); // VDD

    for (int i = 0; i < 16; i++)
        this->_outputs[i] = nts::Tristate::UNDEFINED;
}


void C_4013::simulate(std::size_t pin)
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
    pin--;
    if (this->_pin[2].component)
        this->_pin[2].component->simulate(this->_pin[2].index);
    if (this->_pin[3].component)
        this->_pin[3].component->simulate(this->_pin[3].index);
    if (this->_pin[4].component)
        this->_pin[4].component->simulate(this->_pin[4].index);
    if (this->_pin[5].component)
        this->_pin[5].component->simulate(this->_pin[5].index);
    if (this->_pin[7].component)
        this->_pin[7].component->simulate(this->_pin[7].index);
    if (this->_pin[8].component)
        this->_pin[8].component->simulate(this->_pin[8].index);
    if (this->_pin[9].component)
        this->_pin[9].component->simulate(this->_pin[9].index);
    if (this->_pin[10].component)
        this->_pin[10].component->simulate(this->_pin[10].index);
    for (std::size_t i = 0; i < this->_pinMax; i++)
        calcOutput(i);
}

void C_4013::calcOutput(std::size_t pin)
{
    if (pin == 0) {
        this->_Q1 = this->convertCalc("q", 5, 4, 3, 2, this->_Q1);
        this->_outputs[pin] = this->_Q1;
        return;
    } else if (pin == 1) {
        this->_Qb1 = this->convertCalc("q2", 5, 4, 3, 2, this->_Qb1);
        this->_outputs[pin] = this->_Qb1;
        return;
    } else if (pin == 12) {
        this->_Q2 = this->convertCalc("q", 7, 8, 9, 10, this->_Q2);
        this->_outputs[pin] = this->_Q2;
        return;
    } else if (pin == 11) {
        this->_Qb2 = this->convertCalc("q2", 7, 8, 9, 10, this->_Qb2);
        this->_outputs[pin] = this->_Qb2;
        return;
    }
    this->_outputs[pin] = nts::Tristate::UNDEFINED;
    return;
}

nts::Tristate C_4013::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18, "Set link pin: " + std::to_string(pin));
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4013::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

nts::Tristate C_4013::convertCalc(std::string name, std::size_t inputSet,
std::size_t inputData, std::size_t inputReset, std::size_t clock, std::size_t qVal) const
{
    const int int_pinReset = convertTristateToInt(this->computeInput(inputReset));
    const int int_pinSet = convertTristateToInt(this->computeInput(inputSet));
    const int int_pinData = convertTristateToInt(this->computeInput(inputData));
    const int int_pinClock = convertTristateToInt(this->computeInput(clock));

    if (int_pinReset == -1 || int_pinSet == -1)
        return (nts::Tristate::UNDEFINED);
    if (int_pinReset == 1 && int_pinSet == 1) {
        return (nts::Tristate::TRUE);
    } else if (int_pinSet == 1 && int_pinReset == 0) {
        if (name == "q")
            return (nts::Tristate::TRUE);
        else
            return (nts::Tristate::FALSE);
    } else if (int_pinReset == 1 || (int_pinData == 0 && int_pinClock == 1)) {
        if (name == "q")
            return (nts::Tristate::FALSE);
        else
            return (nts::Tristate::TRUE);
    } else if (int_pinSet == 1 || (int_pinData == 1 && int_pinClock == 1)) {
        if (name == "q")
            return (nts::Tristate::TRUE);
        else
            return (nts::Tristate::FALSE);
    } else if (int_pinData == -1 || int_pinClock == -1)
        return (nts::Tristate::UNDEFINED);
    return convertIntToTristate(qVal);
}

nts::Tristate C_4013::computeOutput(std::size_t pin)
{
    return this->_outputs.at(pin);
}

nts::Tristate C_4013::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4013::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18, "Set link pin: " + std::to_string(pin));
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

void C_4013::dump(void) const
{
    std::cout << "4013" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4013::~C_4013()
{
}
