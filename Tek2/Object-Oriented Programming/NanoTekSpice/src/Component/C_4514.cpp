/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** C_4514
*/

#include "Components.hpp"

C_4514::C_4514() : Component("4514")
{
    this->_pinMax = 24;
    this->_metamorph = nts::Tristate::UNDEFINED;

    this->_map[1 - 1] = std::bind(&C_4514::computeInput, this, std::placeholders::_1); // Strobe
    this->_map[23 - 1] = std::bind(&C_4514::computeInput, this, std::placeholders::_1); // Inhibit

    this->_map[2 - 1] = std::bind(&C_4514::computeInput, this, std::placeholders::_1); // A
    this->_map[3 - 1] = std::bind(&C_4514::computeInput, this, std::placeholders::_1); // B
    this->_map[21 - 1] = std::bind(&C_4514::computeInput, this, std::placeholders::_1); // C
    this->_map[22 - 1] = std::bind(&C_4514::computeInput, this, std::placeholders::_1); // D

    this->_map[11 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 0
    this->_map[9 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 1
    this->_map[10 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 2
    this->_map[8 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 3
    this->_map[7 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 4
    this->_map[6 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 5
    this->_map[5 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 6
    this->_map[4 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 7
    this->_map[18 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 8
    this->_map[17 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 9
    this->_map[20 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 10
    this->_map[19 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 11
    this->_map[14 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 12
    this->_map[13 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 13
    this->_map[16 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 14
    this->_map[15 - 1] = std::bind(&C_4514::computeOutput, this, std::placeholders::_1); // Output 15

    this->_map[12 - 1] = std::bind(&C_4514::computeVSS, this, std::placeholders::_1); // VSS
    this->_map[24 - 1] = std::bind(&C_4514::computeVDD, this, std::placeholders::_1); // VDD

    for (std::size_t i = 0; i < this->_pinMax; i++)
        this->_outputs[i] = nts::Tristate::UNDEFINED;
}

void C_4514::simulate(std::size_t pin)
{
    (void) pin;
    this->_pin[0].component->simulate(this->_pin[0].index); // Simulate strobe
    this->_pin[22].component->simulate(this->_pin[22].index); // Simulate inhibit

    this->_pin[1].component->simulate(this->_pin[1].index); // A
    this->_pin[2].component->simulate(this->_pin[2].index); // B
    this->_pin[20].component->simulate(this->_pin[20].index); // C
    this->_pin[21].component->simulate(this->_pin[21].index); // D
}

nts::Tristate C_4514::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return this->_map[pin - 1](pin - 1);
}

nts::Tristate C_4514::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return this->_pin[pin].component->compute(this->_pin[pin].index);
}

bool C_4514::isNotUndefined(void) const
{
    for (int i = 0; i < 8; i++) {
        if (this->_pin[i].component->compute(this->_pin[i].index) == nts::Tristate::UNDEFINED)
            return false;
    }
    return true;
}

nts::Tristate C_4514::computeOutput(std::size_t pin)
{
    nts::Tristate res = nts::Tristate::UNDEFINED;

    nts::Tristate strobe = this->computeInput(0);
    nts::Tristate inhibit = this->computeInput(22);

    nts::Tristate a = this->computeInput(1);
    nts::Tristate b = this->computeInput(2);
    nts::Tristate c = this->computeInput(20);
    nts::Tristate d = this->computeInput(21);

    std::string binary = "";

    if (strobe != nts::Tristate::FALSE)
        return this->_outputs.at(pin);
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED || c == nts::Tristate::UNDEFINED || d == nts::Tristate::UNDEFINED)
        res = nts::Tristate::UNDEFINED;
    else {
        binary.push_back(convertTristateToInt(d) + '0');
        binary.push_back(convertTristateToInt(c) + '0');
        binary.push_back(convertTristateToInt(b) + '0');
        binary.push_back(convertTristateToInt(a) + '0');
        auto result = std::bitset<4>(binary).to_ulong();

        if (inhibit == nts::Tristate::FALSE) {
            if (pin + 1 == this->_possibleOutputsIndex.at(result)) {
                res = (nts::Tristate::TRUE);
            } else
                res = (nts::Tristate::FALSE);
        } else if (inhibit == nts::Tristate::TRUE) {
            res = (nts::Tristate::FALSE);
        } else {
            res = (nts::Tristate::UNDEFINED);
        }
    }
    this->_outputs[pin] = res;
    return res;
}

nts::Tristate C_4514::computeVSS(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate C_4514::computeVDD(std::size_t pin) const
{
    (void) pin;
    return nts::Tristate::UNDEFINED;
}

void C_4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    if (pin == 12) {
        throw VSSSet("Can't set VSS pin.", 22);
    }
    if (pin == 24) {
        throw VDDSet("Can't set VDD pin", 23);
    }
    this->_pin[pin - 1].component = &other;
    this->_pin[pin - 1].index = otherPin;
}

void C_4514::dump(void) const
{
    std::cout << "4514" << " pins status:" << std::endl;
    for (int i = 0; i < 16; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_4514::~C_4514()
{
}
