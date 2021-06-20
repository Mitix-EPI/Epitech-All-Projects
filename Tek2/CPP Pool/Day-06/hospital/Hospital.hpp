/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** Hospital
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"
#include "SickKoalaList.hpp"

class Hospital {
    public:
        Hospital();
        ~Hospital();
        KoalaDoctorList koalaDoctorList;
        KoalaNurseList koalaNurseList;
        SickKoalaList koalaSickList;
        void addDoctor(KoalaDoctorList *);
        void addSick(SickKoalaList *);
        void addNurse(KoalaNurseList *);
        void run(void);
        void displayArrive(void);
        void displayEndTime(void);

    protected:
    private:
};

#endif /* !HOSPITAL_HPP_ */
