/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** C_4094
*/

#include "Components.hpp"

C_4094::C_4094(): Component("4094")
{
    this->_pinMax = 16;
    this->_metamorph = nts::Tristate::UNDEFINED;

    this->_map[1 - 1] = std::bind(&C_4094::computeInput, this, std::placeholders::_1); // Strobe
    this->_map[2 - 1] = std::bind(&C_4094::computeInput, this, std::placeholders::_1); // Data
    this->_map[3 - 1] = std::bind(&C_4094::computeInput, this, std::placeholders::_1); // Clock
    this->_map[15 - 1] = std::bind(&C_4094::computeInput, this, std::placeholders::_1); // Output Enable

    this->_map[4 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 1
    this->_map[5 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 2
    this->_map[6 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 3
    this->_map[7 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 4
    this->_map[11 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 8
    this->_map[12 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 7
    this->_map[13 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 6
    this->_map[14 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // output 5

    this->_map[9 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // Output QS
    this->_map[10 - 1] = std::bind(&C_4094::computeOutput, this, std::placeholders::_1); // Output QE

    this->_map[8 - 1] = std::bind(&C_4094::computeVSS, this, std::placeholders::_1); // VSS
    this->_map[16 - 1] = std::bind(&C_4094::computeVDD, this, std::placeholders::_1); // VSS

    for (std::size_t i = 0; i < 16; i++)
        this->_outputs[i] = nts::Tristate::UNDEFINED;
}


void C_4094::simulate(std::size_t pin)
{
    pin--;
    this->_pin[0].component->simulate(this->_pin[0].index);
    this->_pin[1].component->simulate(this->_pin[1].index);
    this->_pin[2].component->simulate(this->_pin[2].index);
    this->_pin[14].component->simulate(this->_pin[14].index);

    nts::Tristate strobe = this->computeInput(0);
    nts::Tristate data = this->computeInput(1);
    nts::Tristate clock = this->computeInput(2);
    nts::Tristate enableOutput = this->computeInput(14);


    if (clock != this->_metamorph && enableOutput == nts::Tristate::TRUE) { // Rest of the lines
        this->_metamorph = clock;
        if (clock == nts::Tristate::TRUE && strobe == nts::Tristate::TRUE) {
            this->_outputs[10] = this->_outputs[11]; // 8
            this->_outputs[11] = this->_outputs[12]; // 7
            this->_outputs[12] = this->_outputs[13]; // 6
            this->_outputs[13] = this->_outputs[6]; // 5
            this->_outputs[6] = this->_outputs[5]; // 4
            this->_outputs[5] = this->_outputs[4]; // 3
            this->_outputs[4] = this->_outputs[3]; // 2
            this->_outputs[3] = data; // 1
        }
    }
}

nts::Tristate C_4094::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18, "Set link pin: " + std::to_string(pin));
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4094::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

nts::Tristate C_4094::convertCalc(std::size_t pin1, std::size_t pin2) const
{
    (void) pin1;
    (void) pin2;
    return (nts::Tristate::UNDEFINED);
}

nts::Tristate C_4094::computeOutput(std::size_t pin)
{
    nts::Tristate strobe = this->computeInput(0);
    nts::Tristate data = this->computeInput(1);
    nts::Tristate clock = this->computeInput(2);
    nts::Tristate enableOutput = this->computeInput(14);

    nts::Tristate res = nts::Tristate::UNDEFINED;

    if (strobe == nts::Tristate::UNDEFINED && data == nts::Tristate::UNDEFINED
    && clock == nts::Tristate::UNDEFINED && enableOutput == nts::Tristate::UNDEFINED) // Undefined case
        res = nts::Tristate::UNDEFINED;
    else if (clock == nts::Tristate::TRUE && (pin == 8 || pin == 10)) // Q8 & QS when clock On
        res = this->_outputs.at(11);
    else if (clock == nts::Tristate::FALSE && data == nts::Tristate::TRUE
    && strobe == nts::Tristate::TRUE && enableOutput == nts::Tristate::TRUE) { // Last line of the truth table
        if (pin == 9) // out_qe
            res = this->_outputs.at(11);
        else
            res = this->_outputs.at(pin);
    } else if (enableOutput == nts::Tristate::FALSE) { // 2 firsts lines of the truth table
        if (clock == nts::Tristate::TRUE && pin == 9) // QE
            res = this->_outputs.at(pin);
        else if (clock == nts::Tristate::FALSE && pin == 8) // QS
            res = this->_outputs.at(pin);
        else if (clock == nts::Tristate::FALSE && pin == 9) // QE
            res = this->_outputs.at(11);
        else
            res = nts::Tristate::TRUE;
    } else // REST OF THE LINES
        res = this->_outputs.at(pin);
    this->_outputs[pin] = res;
    return res;
}

nts::Tristate C_4094::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4094::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18, "Set link pin: " + std::to_string(pin));
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

void C_4094::dump(void) const
{
    std::cout << "4094" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4094::~C_4094()
{
}
