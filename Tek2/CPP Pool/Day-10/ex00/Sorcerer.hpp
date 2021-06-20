/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title)
        {
            _name = name;
            _title = title;
            std::cout << name << ", " << title << ", is born!" << std::endl;
        }
        ~Sorcerer()
        {
            std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
        }

        // getters
        std::string getName(void) const { return _name; }
        std::string getTitle(void) const { return _title; }

        // setters
        void setName(std::string &name) { _name = name; }
        void setTitle(std::string &title) { _title = title; }

        void polymorph(const Victim &victim) const;

    protected:
    private:
        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &s, const Sorcerer &d);

#endif /* !SORCERER_HPP_ */
