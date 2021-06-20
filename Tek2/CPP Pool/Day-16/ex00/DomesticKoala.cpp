/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &elem)
{
    this->_koalaAction = elem;
}

DomesticKoala::DomesticKoala(const DomesticKoala &oldKoala)
{
    this->_actions = oldKoala._actions;
    this->_chars = oldKoala._chars;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &oldKoala)
{
    this->_actions = oldKoala._actions;
    this->_chars = oldKoala._chars;
    return *this;
}

DomesticKoala::~DomesticKoala()
{
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    if (command && action) {
        this->_actions.push_back(action);
        this->_chars.push_back(command);
    }
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    if (command) {
        int i = 0;
        for (auto it = this->_chars.begin(); it != this->_chars.end(); ++it, ++i) {
            if (*it == command) {
                this->_chars.erase(it);
                this->_actions.erase(this->_actions.begin() + i);
                return;
            }
        }
    }
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    int i = 0;
    for (auto it = this->_chars.begin(); it != this->_chars.end(); ++it, ++i) {
        if (*it == command) {
            methodPointer_t func = this->_actions[i];
            (this->_koalaAction.*func)(param);
            return;
        }
    }
}

void DomesticKoala::setKoalaAction(KoalaAction &elem)
{
    this->_koalaAction = elem;
    this->_actions.clear();
    this->_chars.clear();
}
