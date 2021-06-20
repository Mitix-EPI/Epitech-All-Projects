/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-alexandre.juan
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key)
{
    this->_key = key;
}

OneTime::~OneTime()
{
}

void OneTime::encryptChar(char plainchar)
{
    char tmp = 0;
    if (this->_key.at(this->_index) >= 'A' && this->_key.at(this->_index) <= 'Z') {
        tmp = this->_key.at(this->_index) - 'A';
    } else if (this->_key.at(this->_index) >= 'a' && this->_key.at(this->_index) <= 'z') {
        tmp = this->_key.at(this->_index) - 'a';
    }
    if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar -= 'A';
        plainchar += tmp;
        plainchar %= 26;
        plainchar += 'A';
    } else if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar -= 'a';
        plainchar += tmp;
        plainchar %= 26;
        plainchar += 'a';
    }
    this->_index ++;
    if (this->_index == this->_key.size())
        this->_index = 0;
    std::cout << (char)(plainchar);
}

void OneTime::decryptChar(char plainchar)
{
    char tmp = 0;
    if (this->_key.at(this->_index) >= 'A' && this->_key.at(this->_index) <= 'Z') {
        tmp = this->_key.at(this->_index) - 'A';
    } else if (this->_key.at(this->_index) >= 'a' && this->_key.at(this->_index) <= 'z') {
        tmp = this->_key.at(this->_index) - 'a';
    }
    if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar -= 'Z';
        plainchar -= tmp;
        plainchar %= 26;
        plainchar += 'Z';
    } else if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar -= 'z';
        plainchar -= tmp;
        plainchar %= 26;
        plainchar += 'z';
    }
    this->_index ++;
    if (this->_index == this->_key.size())
        this->_index = 0;
    std::cout << (char)(plainchar);
}

void OneTime::reset(void)
{
    this->_index = 0;
}
