/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "Event.hpp"
#include <list>
#include <iostream>

class EventManager
{
public:
    EventManager();
    EventManager(EventManager const &other);
    EventManager &operator=(EventManager const &rhs);
    ~EventManager();

    // Adds an Event to the list .
    // If the event time is prior to current time , the event is not added .
    // If there is already an event at this time , the new event is added after it.
    void addEvent(const Event &e);
    // Deletes all the Events occuring at T time
    void removeEventsAt(unsigned int time);
    // Shows the events list using the following format :
    // 8: Wake up / 9: Day start / 12: Eat / ...
    void dumpEvents() const;
    // Shows all the events occuring at T time , using the above format
    void dumpEventAt(unsigned int time) const;
    // Adds t time units to the current time .
    // Displays the description of all events that occured between the previous
    // current time and the new one , and deletes these events from the list .
    void addTime(unsigned int time);
    // Adds an event list to the current list .
    void addEventList(const std::list<Event> &events);

    std::list<Event> _list;
    unsigned int _current_time;

protected:
private:
};

#endif /* !EVENTMANAGER_HPP_ */
