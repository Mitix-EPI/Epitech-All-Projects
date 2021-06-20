/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(std::string &name, const std::string &type): Object(name, type)
{
    this->_name = name;
    this->_obj = nullptr;
    this->_open = true;
}

Wrap::~Wrap()
{
    if (this->_obj)
        delete this->_obj;
}

void Wrap::wrapMeThat(Object *newObj)
{
    if (newObj == nullptr) {
        raise("Error: Object given is null");
        return;
    }
    if (this->getObject() != nullptr) {
        raise("Error: This Object already contains another Object");
        return;
    }
    if (!this->getOpen() && this->getType() == BOX) {
        raise("Error: Box is closed");
        return;
    }
    if (this->getType() == BOX && !this->isAToy(newObj)) {
        raise("Error: Only Toys can be putted in Box");
        return;
    }
    if (this->getType() == PAPER && newObj->getType() != BOX) {
        raise("Error: Only Box can be wrapped");
        return;
    }
    this->_obj = newObj;
}

void Wrap::closeMe(void)
{
    this->_open = false;
}

bool Wrap::isAToy(Object *newObject)
{
    if (newObject->getType() == TOY) {
        return true;
    }
    if (newObject->getType() == PONY) {
        return true;
    }
    if (newObject->getType() == TED) {
        return true;
    }
    return false;
}

void Wrap::openMe(void)
{
    this->_open = true;
}
