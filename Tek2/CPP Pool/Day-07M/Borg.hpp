/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07M-alexandre.juan
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_
namespace Borg {
    class Ship;
}

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Destination.hpp"


class Borg::Ship {
    public:
        Ship(int weaponFrequency, short repair = 3, int side = 300, int maxWarp = 9);
        ~Ship();
        void setupCore(WarpSystem::Core *);
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        int getShield(void);
        void setShield(int shield);
        int getWeaponFrequency(void);
        void setWeaponFrequency(int frequency);
        short getRepair();
        void setRepair(short repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair(void);

    protected:
    private:
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        int _weaponFrequency;
        short _repair;
        int _shield;
        Destination _location;
        Destination _home;

};

#endif /* !BORG_HPP_ */
