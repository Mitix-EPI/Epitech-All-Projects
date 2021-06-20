/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** Event
*/

#include "Event.hpp"

Event::Event()
{
    this->_time = 0;
    this->_event = "";
}

Event::Event(unsigned int time, const std::string &event)
{
    this->_time = time;
    this->_event = event;
}

Event::Event(const Event &other)
{
    this->_time = other._time;
    this->_event = other._event;
}

Event &Event::operator=(const Event &rhs)
{
    this->_event = rhs._event;
    this->_time = rhs._time;
    return *this;
}

Event::~Event()
{
}
