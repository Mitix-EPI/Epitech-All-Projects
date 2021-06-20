/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *);
        ~KoalaDoctorList();
        KoalaDoctor *doc;
        KoalaDoctorList *next;
        bool isEnd(void);
        void append(KoalaDoctorList *);
        KoalaDoctor *getFromName(std::string);
        KoalaDoctorList *remove(KoalaDoctorList *);
        KoalaDoctorList *removeFromName(std::string);
        KoalaDoctor *getContent(void);
        KoalaDoctorList *getNext(void);
        void dump(void);

    protected:
    private:
};

#endif /* !KOALADOCTORLIST_HPP_ */
