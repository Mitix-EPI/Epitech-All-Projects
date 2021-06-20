/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD10-alexandre.juan
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <string>
#include <iostream>

class Victim {
    public:
        Victim(std::string name)
        {
            _name = name;
            std::cout << "Some random victim called " << name << " just popped!" << std::endl;
        }
        ~Victim()
        {
            std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
        }

        // getters
        std::string getName(void) const { return _name; }

        // setters
        void setName(std::string &name) { _name = name; }

        virtual void getPolymorphed(void) const;

    protected:
        std::string _name;
    private:
};

std::ostream &operator<<(std::ostream &s, const Victim &d);

#endif /* !VICTIM_HPP_ */
