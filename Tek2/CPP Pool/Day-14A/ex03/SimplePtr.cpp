/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14A-alexandre.juan
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"
#include <memory>

SimplePtr::SimplePtr(BaseComponent *rawPtr)
{
    this->_rawPtr = rawPtr;
}

SimplePtr::~SimplePtr()
{
    delete this->_rawPtr;
}

SimplePtr &SimplePtr::operator=(SimplePtr const &otherPtr)
{
    this->_rawPtr = otherPtr.get();
    return *this;
}

BaseComponent *SimplePtr::get(void) const
{
    return this->_rawPtr;
}
