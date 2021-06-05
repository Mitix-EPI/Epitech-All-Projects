/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** C_Logger
*/

#include "Components.hpp"

C_Logger::C_Logger() : Component("logger")
{
    this->_pinMax = 10;

    this->_map[1 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 1
    this->_map[2 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 2
    this->_map[3 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 3
    this->_map[4 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 4
    this->_map[5 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 5
    this->_map[6 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 6
    this->_map[7 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 7
    this->_map[8 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // 8

    this->_map[9 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // Clock
    this->_map[10 - 1] = std::bind(&C_Logger::computeInput, this, std::placeholders::_1); // Inhibit
}

bool C_Logger::computeToBinary(nts::Tristate state) const
{
    if (state == nts::Tristate::FALSE || state == nts::Tristate::UNDEFINED) {
        return (false);
    }
    return (true);
}

bool C_Logger::isNotUndefined(void) const
{
    for (int i = 0; i < 8; i++) {
        if (this->_pin[i].component->compute(this->_pin[i].index) == nts::Tristate::UNDEFINED)
            return false;
    }
    return true;
}

void C_Logger::simulate(std::size_t pin)
{
    (void) pin;
    this->_pin[0].component->simulate(this->_pin[0].index);
    this->_pin[1].component->simulate(this->_pin[1].index);
    this->_pin[2].component->simulate(this->_pin[2].index);
    this->_pin[3].component->simulate(this->_pin[3].index);
    this->_pin[4].component->simulate(this->_pin[4].index);
    this->_pin[5].component->simulate(this->_pin[5].index);
    this->_pin[6].component->simulate(this->_pin[6].index);
    this->_pin[7].component->simulate(this->_pin[7].index);
    this->_pin[8].component->simulate(this->_pin[8].index);
    this->_pin[9].component->simulate(this->_pin[9].index);
    if (this->computeInput(9) != nts::Tristate::TRUE && this->computeInput(8) == nts::Tristate::TRUE && this->isNotUndefined()) {
        std::ofstream binaryFile("./log.bin", std::ios::binary | std::ios_base::app | std::ios_base::in | std::ios_base::out); // fstream::in | fstream::out | fstream::app
        std::bitset<8> tristateBits;
        tristateBits[0] = this->computeToBinary(this->computeInput(0));
        tristateBits[1] = this->computeToBinary(this->computeInput(1));
        tristateBits[2] = this->computeToBinary(this->computeInput(2));
        tristateBits[3] = this->computeToBinary(this->computeInput(3));
        tristateBits[4] = this->computeToBinary(this->computeInput(4));
        tristateBits[5] = this->computeToBinary(this->computeInput(5));
        tristateBits[6] = this->computeToBinary(this->computeInput(6));
        tristateBits[7] = this->computeToBinary(this->computeInput(7));
        binaryFile << (std::uint_fast8_t)tristateBits.to_ulong();
        binaryFile.close();
    }
}

nts::Tristate C_Logger::compute(std::size_t pin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    return (this->_map[pin - 1](pin - 1));
}

nts::Tristate C_Logger::computeInput(std::size_t pin) const
{
    if (this->_pin[pin].component == nullptr) {
        return nts::Tristate::UNDEFINED;
    }
    return (this->_pin[pin].component->compute(this->_pin[pin].index));
}

// INPUTTMP -> CLOCK -> LOGGER

void C_Logger::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin <= 0 || pin > this->_pinMax) {
        throw InvalidPin("This pin doesn't exists on this component", 18);
    }
    this->_pin[pin - 1].component = &other;
    this->_pin[pin - 1].index = otherPin;
}

void C_Logger::dump(void) const
{
    std::cout << "Logger" << " pins status:" << std::endl;
    for (std::size_t i = 0; i < this->_pinMax; i++) {
        if (this->_pin[i].component) {
            std::cout << "\t pin [" << i << "]: ";
            this->_pin[i].component->dump();
        }
    }
}

C_Logger::~C_Logger()
{
}
