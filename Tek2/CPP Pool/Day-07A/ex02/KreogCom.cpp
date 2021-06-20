/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07A-alexandre.juan
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : _x(x), _y(y), m_serial(serial), _next(nullptr)
{
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newNode = new KreogCom(x, y, serial);

    newNode ->_next = _next;
    this->_next = newNode;
}

KreogCom *KreogCom::getCom(void)
{
    if (_next == nullptr)
        return nullptr;
    return _next;
}

void KreogCom::removeCom(void)
{
    if (!_next)
        return;
    KreogCom *tmp = _next;
    _next = tmp->_next;
    tmp->~KreogCom();
}

void KreogCom::ping(void) const
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad(void) const
{
    if (_next == nullptr)
        return ping();
    if (_next)
        this->_next->locateSquad();
    this->ping();
}
