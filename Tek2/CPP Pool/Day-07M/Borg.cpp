/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07M-alexandre.juan
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair, int side, int maxWarp) : _side(side), _maxWarp(maxWarp), _weaponFrequency(weaponFrequency), _repair(repair)
{
    _home = UNICOMPLEX;
    _location = _home;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *coreEngine)
{
    _core = coreEngine;
}

void Borg::Ship::checkCore(void)
{
    if (_core->checkReactor()->isStable()) {
        std::cout << "Everything is in order" << std::endl;
    } else {
        std::cout << "Critical failure imminent" << std::endl;
    }
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move()
{
    if (_location != _home && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

int Borg::Ship::getShield(void)
{
    return _shield;
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency(void)
{
    return _weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair(void)
{
    return _repair;
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    int shieldRemaining = target->getShield();
    target->setShield(shieldRemaining - _weaponFrequency);
}

void Borg::Ship::fire(Federation::Ship *target)
{
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    target->getCore()->checkReactor()->setStability(false);
}

void Borg::Ship::repair(void)
{
    if (_repair > 0) {
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
        _repair -= 1;
        _shield = 100;
    } else {
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }

}
