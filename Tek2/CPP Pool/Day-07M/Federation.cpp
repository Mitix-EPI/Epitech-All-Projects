/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07M-alexandre.juan
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) : _length(length), _width(width), _name(name), _maxWarp(maxWarp), _shield(100), _photonTorpedo(torpedo)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    _home = EARTH;
    _location = _home;
    if (torpedo) {
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
    }
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *coreEngine)
{
    _core = coreEngine;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    std::string status = _core->checkReactor()->isStable() ? "stable" : "unstable";
    std::cout << "USS " << _name << ": The core is " << status << " at the time." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move()
{
    if (_location != _home && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

int Federation::Starfleet::Ship::getShield(void)
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo(void)
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo > 0) {
        _photonTorpedo -= 1;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        int shieldRemaining = target->getShield();
        target->setShield(shieldRemaining - 50);
    } else {
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
    }
    // TODO
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo <= 0) {
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
        return;
    }
    if (_photonTorpedo - torpedoes >= 0) {
        _photonTorpedo -= torpedoes;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        int shieldRemaining = target->getShield();
        target->setShield(shieldRemaining - (50 * torpedoes));
    } else {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
    }
    // TODO
}

Federation::Ship::Ship(int length, int width, std::string name, short maxWarp) : _length(length), _width(width), _name(name), _maxWarp(maxWarp)
{
    _home = VULCAN;
    _location = _home;
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *coreEngine)
{
    _core = coreEngine;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    std::string status = _core->checkReactor()->isStable() ? "stable" : "unstable";
    std::cout << _name << ": The core is " << status << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    if (_location != _home && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

WarpSystem::Core *Federation::Ship::getCore(void)
{
    return _core;
}

Federation::Starfleet::Captain::Captain(std::string name, int age) : _name(name), _age(age)
{
}

Federation::Starfleet::Captain::~Captain()
{
}

int Federation::Starfleet::Captain::getAge(void)
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

std::string Federation::Starfleet::Captain::getName(void)
{
    return _name;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}
