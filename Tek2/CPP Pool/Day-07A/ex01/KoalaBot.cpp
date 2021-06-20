/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string const &serial) : _serial(serial)
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tmp = arms;
    arms = _arms;
    _arms = tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp = legs;
    legs = _legs;
    _legs = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = head;
    head = _head;
    _head = tmp;
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    std::cout << "\t" << std::fixed;
    _arms.informations();
    std::cout << "\t" << std::fixed;
    _legs.informations();
    std::cout << "\t" << std::fixed;
    _head.informations();
}

bool KoalaBot::status(void) const
{
    if (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional())
        return true;
    return false;
}
