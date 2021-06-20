/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14A-alexandre.juan
** File description:
** RefPtr
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(void)
{
    this->_rawPtr = NULL;
}

RefPtr::RefPtr(BaseComponent *rawPtr)
{
    this->_rawPtr = rawPtr;
}

RefPtr::RefPtr(RefPtr const &other)
{
    this->clone(other);
}

void RefPtr::clone(RefPtr const &other)
{
    this->_rawPtr = other._rawPtr;
}

RefPtr &RefPtr::operator=(RefPtr const &other)
{
    if (this->_rawPtr)
        delete this->_rawPtr;
    this->clone(other);
    return *this;
}

RefPtr &RefPtr::operator=(BaseComponent *rawPtr)
{
    if (this->_rawPtr)
        delete this->_rawPtr;
    this->_rawPtr = rawPtr;
    return *this;
}

RefPtr::~RefPtr()
{
    // if (this->_rawPtr)
    //     delete this->_rawPtr;
}
