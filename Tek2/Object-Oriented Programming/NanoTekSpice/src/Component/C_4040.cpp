/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4040
*/

#include "Components.hpp"

C_4040::C_4040() : Component("4040")
{
    this->_computed = false;

    this->_pinMax = 16;
    this->_increment = 0;
    this->_metamorph = nts::Tristate::UNDEFINED;
    this->_binary = "";

    this->_map[11 - 1] = std::bind(&C_4040::computeInput, this, std::placeholders::_1); // Reset

    this->_map[10 - 1] = std::bind(&C_4040::computeInput, this, std::placeholders::_1); // Clock

    this->_map[1 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[2 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[3 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[4 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[5 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[6 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[7 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[9 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[12 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[13 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[14 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output
    this->_map[15 - 1] = std::bind(&C_4040::computeOutput, this, std::placeholders::_1); // Output

    this->_map[8 - 1] = std::bind(&C_4040::computeVSS, this, std::placeholders::_1); // VSS
    this->_map[16 - 1] = std::bind(&C_4040::computeVDD, this, std::placeholders::_1); // VDD

    for (int i = 0; i < 16; i++)
        this->_outputs[i] = nts::Tristate::UNDEFINED;
}

void C_4040::simulate(std::size_t pin)
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
    this->_pin[9].component->simulate(this->_pin[9].index);
    this->_pin[10].component->simulate(this->_pin[10].index);
    nts::Tristate metaClock = this->computeInput(9);
    if (metaClock != this->_metamorph && metaClock != nts::Tristate::UNDEFINED) {
        this->_metamorph = metaClock;
        if (this->computeInput(9) == 0) {
            this->progress();
            this->setOutputs();
        }
        if (this->computeInput(10) == 1)
            this->reset();
    }
    if (metaClock == nts::Tristate::UNDEFINED) {
        for (const auto &it : this->_possibleOutputsIndex) {
            this->_outputs[it] = nts::UNDEFINED;
        }
    }
}

void C_4040::setOutputs(void)
{
    std::string binaryReverse = this->_binary;
    std::reverse(binaryReverse.begin(), binaryReverse.end());
    std::size_t index = 0;

    for (const auto &it : this->_possibleOutputsIndex) {
        this->_outputs[it] = convertIntToTristate((int)(binaryReverse.c_str()[index++] - '0'));
    }
}

long unsigned int C_4040::calcLinkedOutputs(void) const
{
    long unsigned int res = 0;

    for (const auto &it : this->_possibleOutputsIndex)
        if (this->_pin[it].component != nullptr)
            res++;
    return res;
}

void C_4040::progress(void)
{
    if (std::bitset<12>(this->_binary).to_ulong() == pow(2, calcLinkedOutputs())) {
        this->_increment = 0;
    } else {
        this->_increment += 1;
    }
    this->_binary = std::bitset<12>(this->_increment).to_string();
}

void C_4040::reset(void)
{
    for (auto &it : this->_possibleOutputsIndex) {
        this->_outputs[it] = nts::Tristate::FALSE;
    }
    this->_increment = 0;
}

nts::Tristate C_4040::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4040::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

nts::Tristate C_4040::computeOutput(std::size_t pin) const
{
    return this->_outputs.at(pin);
}

nts::Tristate C_4040::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4040::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C_4040::dump(void) const
{
    std::cout << "4040" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4040::~C_4040()
{
}
