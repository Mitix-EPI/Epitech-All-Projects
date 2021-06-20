/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : Fingerprint((size_t)random()), Exp(0)
{
}

DroidMemory::~DroidMemory()
{
}


DroidMemory &DroidMemory::operator<<(const DroidMemory &ptr)
{
    Exp += ptr.Exp;
    Fingerprint ^= ptr.Fingerprint;
    return *this;
}

const DroidMemory &DroidMemory::operator>>(DroidMemory &ptr) const
{
    ptr.Exp += Exp;
    ptr.Fingerprint ^= Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &ptr)
{
    Exp += ptr.Exp;
    Fingerprint ^= ptr.Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(const size_t &ptr)
{
    Exp += ptr;
    Fingerprint ^= ptr;
    return *this;
}

DroidMemory &DroidMemory::operator+(const DroidMemory &ptr) const
{
    DroidMemory *res = new DroidMemory;

    res->setExp(this->getExp() + ptr.getExp());
    res->setFingerprint(this->getFingerprint() ^ ptr.getFingerprint());
    return *res;
}

DroidMemory &DroidMemory::operator+(const size_t &ptr) const
{
    DroidMemory *res = new DroidMemory;

    res->setExp(this->getExp() + ptr);
    res->setFingerprint(this->getFingerprint() ^ ptr);
    return *res;
}

DroidMemory &DroidMemory::operator=(const DroidMemory &ptr)
{
    this->setFingerprint(ptr.getFingerprint());
    this->setExp(ptr.getExp());
    return *this;
}

void DroidMemory::setFingerprint(size_t newFingerprint)
{
    Fingerprint = newFingerprint;
}

void DroidMemory::setExp(size_t newExp)
{
    Exp = newExp;
}


std::ostream &operator<<(std::ostream &s, const DroidMemory &d)
{
    return s << "DroidMemory '" << d.getFingerprint() << "', " << d.getExp();
}
