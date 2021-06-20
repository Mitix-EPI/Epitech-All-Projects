/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *);
        ~SickKoalaList();
        SickKoala *patient;
        SickKoalaList *next;
        bool isEnd(void);
        void append(SickKoalaList *);
        SickKoala *getFromName(std::string);
        SickKoalaList *remove(SickKoalaList *);
        SickKoalaList *removeFromName(std::string);
        SickKoala *getContent(void);
        SickKoalaList *getNext(void);
        void dump(void);

    protected:
    private:
};

#endif /* !SICKKOALALIST_HPP_ */
