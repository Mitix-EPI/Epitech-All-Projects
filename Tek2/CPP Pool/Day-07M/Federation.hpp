/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07M-alexandre.juan
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ensign;
        class Ship;
    }
    class Ship;
}

#include <iostream>
#include <string>
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include "Destination.hpp"

class Federation::Starfleet::Captain {
    public:
        Captain(std::string _name, int _age = 20);
        ~Captain();
        int getAge(void);
        void setAge(int);
        std::string getName(void);

    protected:
    private:
        std::string _name;
        int _age;
};

class Federation::Starfleet::Ensign {
    public:
        Ensign(std::string);
        ~Ensign();

    protected:
    private:
        std::string _name;
};

class Federation::Starfleet::Ship {
    public:
        Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 0);
        ~Ship();
        void setupCore(WarpSystem::Core *);
        void checkCore(void);
        void promote(Captain *captain);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        int getShield(void);
        void setShield(int shield);
        int getTorpedo(void);
        void setTorpedo(int torpedo);
        void fire(Borg::Ship *target);
        void fire(int torpedoes, Borg::Ship *target);

    protected:
    private:
        WarpSystem::Core *_core;
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        Captain *_captain;
        Destination _location;
        Destination _home;
        int _shield;
        int _photonTorpedo;
};

class Federation::Ship {
    public:
        Ship(int length, int with, std::string name, short maxWarp = 1);
        ~Ship();
        void setupCore(WarpSystem::Core *);
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        WarpSystem::Core *getCore(void);

    protected:
    private:
        WarpSystem::Core *_core;
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        Destination _location;
        Destination _home;
};

#endif /* !FEDERATION_HPP_ */
