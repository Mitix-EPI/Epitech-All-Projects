/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *);
        ~KoalaNurseList();
        KoalaNurse *nurse;
        KoalaNurseList *next;
        bool isEnd(void);
        void append(KoalaNurseList *);
        KoalaNurse *getFromID(int);
        KoalaNurseList *remove(KoalaNurseList *);
        KoalaNurseList *removeFromID(int);
        KoalaNurse *getContent(void);
        KoalaNurseList *getNext(void);
        void dump(void);

    protected:
    private:
};

#endif /* !KOALANURSELIST_HPP_ */
