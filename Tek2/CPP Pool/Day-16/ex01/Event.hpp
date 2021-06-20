/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

class Event {
    public:
        Event();
        Event(unsigned int time, const std::string &event);
        Event(const Event &other);
        Event &operator=(const Event &rhs);
        ~Event();

        unsigned int getTime(void) const { return this->_time; };
        const std::string &getEvent() const { return this->_event; };
        void setTime(unsigned int time) { this->_time = time; };
        void setEvent(const std::string &event) { this->_event = event; };

    protected:
    private:
        std::string _event;
        int _time;
};

#endif /* !EVENT_HPP_ */
