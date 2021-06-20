/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD08-alexandre.juan
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>
#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();

        // operators
        DroidMemory &operator<<(const DroidMemory &ptr);
        const DroidMemory &operator>>(DroidMemory &ptr) const;
        DroidMemory &operator+=(const DroidMemory &ptr);
        DroidMemory &operator+=(const size_t &ptr);
        DroidMemory &operator+(const DroidMemory &ptr) const;
        DroidMemory &operator+(const size_t &ptr) const;
        DroidMemory &operator=(const DroidMemory &ptr);

        // getters
        size_t getFingerprint(void) const { return Fingerprint; };
        size_t getExp(void) const { return Exp; };

        // setters
        void setFingerprint(size_t Fingerprint);
        void setExp(size_t Exp);

    protected:
    private:
        size_t Fingerprint;
        size_t Exp;
};

std::ostream &operator<<(std::ostream &s, const DroidMemory &d);

#endif /* !DROIDMEMORY_HPP_ */
