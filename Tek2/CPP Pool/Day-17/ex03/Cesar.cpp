/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-alexandre.juan
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar() : _interval(3)
{
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar -= 'A';
        plainchar += this->_interval;
        plainchar %= 26;
        plainchar += 'A';
    } else if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar -= 'a';
        plainchar += this->_interval;
        plainchar %= 26;
        plainchar += 'a';
    }
    this->_interval ++;
    if (this->_interval == 27)
        this->_interval = 1;
    std::cout << (char)(plainchar);
}

void Cesar::decryptChar(char plainchar)
{
    if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar -= 'Z';
        plainchar -= this->_interval;
        plainchar %= 26;
        plainchar += 'Z';
    } else if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar -= 'z';
        plainchar -= this->_interval;
        plainchar %= 26;
        plainchar += 'z';
    }
    this->_interval ++;
    if (this->_interval == 27)
        this->_interval = 1;
    std::cout << (char)(plainchar);
}

void Cesar::reset(void)
{
    this->_interval = 3;
}
