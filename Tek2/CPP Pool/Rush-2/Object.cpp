/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(std::string &name, const std::string &type)
{
    this->_name = name;
    this->_type = type;
    this->_obj = nullptr;
}

Object::Object(const Object *newObj)
{
    this->_name = newObj->_name;
    this->_type = newObj->_type;
    this->_obj = nullptr;
    if (this->_type.compare(BOX) == 0 || this->_type.compare(PAPER) == 0) {
        this->_obj = new Object(newObj->_obj);
        this->_open = newObj->_open;
    }
}
Object::~Object()
{
}

std::ostream &operator<<(std::ostream &s, Object &obj)
{
    s << "I'm " << obj.getName() << " and I am a " << obj.getType() << std::endl;
    return (s);
}
