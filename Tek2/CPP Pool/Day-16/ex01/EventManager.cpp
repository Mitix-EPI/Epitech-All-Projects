/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** EventManager
*/

#include "EventManager.hpp"

EventManager::EventManager() : _current_time(0)
{
}

EventManager::EventManager(EventManager const &other)
{
    this->_current_time = other._current_time;
    this->_list = other._list;
}

EventManager &EventManager::operator=(EventManager const &other)
{
    this->_current_time = other._current_time;
    this->_list = other._list;
    return *this;
}

EventManager::~EventManager()
{
}

bool sortByHour(const Event &a, const Event &b)
{
    return a.getTime() < b.getTime();
}

void EventManager::addEvent(const Event &e)
{
    if (e.getTime() >= this->_current_time) {
        this->_list.push_back(e);
        this->_list.sort(sortByHour);
    }
}

void EventManager::removeEventsAt(unsigned int time)
{
    unsigned int count = 0;
    for (auto it = this->_list.begin(); it != this->_list.end(); ++count) {
        if ((*it).getTime() == time) {
            it = this->_list.erase(it);
        } else {
            ++it;
        }
    }
}

void EventManager::dumpEvents(void) const
{
    for (auto it = this->_list.begin(); it != this->_list.end(); ++it) {
        std::cout << (*it).getTime() << ": " << (*it).getEvent() << std::endl;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (auto it = this->_list.begin(); it != this->_list.end(); ++it) {
        if ((*it).getTime() == time) {
            std::cout << (*it).getTime() << ": " << (*it).getEvent() << std::endl;
        }
    }
}

void EventManager::addTime(unsigned int time)
{
    time += this->_current_time;
    unsigned int count = 0;
    for (auto it = this->_list.begin(); it != this->_list.end(); ++count) {
        if ((*it).getTime() <= time && (*it).getTime() >= this->_current_time) {
            std::cout << (*it).getEvent() << std::endl;
            it = this->_list.erase(it);
        } else {
            ++it;
        }
    }
    this->_current_time = time;
}

void EventManager::addEventList(const std::list<Event> &events)
{
    // events.sort(sortByHour);
    for (auto tmp : events) {
        this->addEvent(tmp);
    }
    this->_list.sort(sortByHour);
}
