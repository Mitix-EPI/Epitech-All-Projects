/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include "Droid.hpp"

class Carrier {
    public:
        Carrier(std::string) : Id(""), Energy(300), Attack(100), Toughness(90), Speed(0), _size(0) { }
        ~Carrier();

        // operators
        Carrier &operator<<(const Droid *ptr);
        Carrier &operator<<(size_t &batterie);
        Carrier &operator>>(Droid *ptr);
        Droid *operator[](size_t index);
        void operator~() { updateSpeed(); };
        bool operator()(int x, int y);

        // getters
        std::string getId(void) const { return Id; }
        size_t getEnergy(void) const { return Energy; }
        size_t getAttack(void) const { return Attack; }
        size_t getToughness(void) const { return Toughness; }
        size_t getSpeed(void) const { return Speed; }
        Droid *getDroids(size_t index) const { return Droids[index]; }
        size_t getSize(void) const;

        // setters
        void setId(std::string newId);
        void setEnergy(size_t newEnergy);
        void setSpeed(size_t newSpeed);

        void updateSpeed(void);

    protected:
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        size_t Speed;
        Droid *Droids[5];
        size_t _size;
};

std::ostream &operator<<(std::ostream &s, const Carrier &c);

#endif /* !CARRIER_HPP_ */
