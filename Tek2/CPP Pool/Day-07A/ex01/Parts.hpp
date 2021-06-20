/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>
#include <iostream>

class Arms {
    public:
        Arms(std::string const &serial = "A-01", bool functional = true);
        ~Arms();
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;

    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(std::string const &serial = "L-01", bool functional = true);
        ~Legs();
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;

    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(std::string const &serial = "H-01", bool functional = true);
        ~Head();
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;

    protected:
    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
