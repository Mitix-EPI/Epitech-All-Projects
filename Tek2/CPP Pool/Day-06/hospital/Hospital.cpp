/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** Hospital
*/

#include "Hospital.hpp"

Hospital::Hospital() : koalaDoctorList(nullptr), koalaNurseList(nullptr), koalaSickList(nullptr)
{
}

Hospital::~Hospital()
{
}

void Hospital::addDoctor(KoalaDoctorList *doc)
{
    if (koalaDoctorList.getFromName(doc->doc->getName())) {
        return;
    } else {
        if (koalaDoctorList.doc == nullptr) {
            this->koalaDoctorList = *doc;
        } else {
            this->koalaDoctorList.append(doc);
        }
    }
}

void Hospital::addSick(SickKoalaList *sick)
{
    if (koalaSickList.getFromName(sick->patient->getName())) {
        return;
    } else {
        if (this->koalaSickList.patient == nullptr) {
            this->koalaSickList = *sick;
            this->koalaSickList.next = nullptr;
        } else {
            this->koalaSickList.append(sick);
        }
    }
}

void Hospital::addNurse(KoalaNurseList *nurse)
{
    if (koalaNurseList.getFromID(nurse->nurse->getID())) {
        return;
    } else {
        if (this->koalaNurseList.nurse == nullptr) {
            this->koalaNurseList = *nurse;
        } else {
            this->koalaNurseList.append(nurse);
        }
    }
}

void Hospital::displayArrive(void)
{
    KoalaDoctorList tmp1 = koalaDoctorList;
    SickKoalaList tmp2 = koalaSickList;
    KoalaNurseList tmp3 = koalaNurseList;

    for (; !tmp1.isEnd(); tmp1 = *tmp1.getNext()) {
        std::cout << "[HOSPITAL] Doctor " << tmp1.doc->getName() << " just arrived!" << std::endl;
        tmp1.doc->timeCheck();
    }
    std::cout << "[HOSPITAL] Doctor " << tmp1.doc->getName() << " just arrived!" << std::endl;
    tmp1.doc->timeCheck();

    for (; !tmp2.isEnd(); tmp2 = *tmp2.getNext())
        std::cout << "[HOSPITAL] Patient " << tmp2.patient->getName() << " just arrived!" << std::endl;
    std::cout << "[HOSPITAL] Patient " << tmp2.patient->getName() << " just arrived!" << std::endl;

    for (; !tmp3.isEnd(); tmp3 = *tmp3.getNext()) {
        std::cout << "[HOSPITAL] Nurse " << tmp3.nurse->getID() << " just arrived!" << std::endl;
        tmp3.nurse->timeCheck();
    }
    std::cout << "[HOSPITAL] Nurse " << tmp3.nurse->getID() << " just arrived!" << std::endl;
    tmp3.nurse->timeCheck();
}

void Hospital::displayEndTime(void)
{
    KoalaDoctorList tmp1 = koalaDoctorList;
    SickKoalaList tmp2 = koalaSickList;
    KoalaNurseList tmp3 = koalaNurseList;

    for (tmp3 = koalaNurseList; tmp3.next != nullptr; tmp3 = *tmp3.next) {
        tmp3.nurse->timeCheck();
    }
    tmp3.nurse->timeCheck();
    for (tmp1 = koalaDoctorList; tmp1.next != nullptr; tmp1 = *tmp1.next) {
        tmp1.doc->timeCheck();
    }
    tmp1.doc->timeCheck();
}

void Hospital::run(void)
{
    displayArrive();
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    koalaDoctorList.dump();
    koalaNurseList.dump();
    koalaSickList.dump();
    std::cout << std::endl;

    KoalaDoctorList tmp1 = koalaDoctorList;
    SickKoalaList tmp2 = koalaSickList;
    KoalaNurseList tmp3 = koalaNurseList;
    while (tmp2.patient) {
        tmp1.doc->diagnose(tmp2.patient);
        std::string drug = tmp3.nurse->readReport(tmp2.patient->getName() + ".report");
        tmp3.nurse->giveDrug(drug, tmp2.patient);
        tmp1.next != nullptr ? tmp1 = *tmp1.next : tmp1 = koalaDoctorList;
        if (tmp2.next) {
            tmp2 = *tmp2.next;
        } else {
            break;
        }
        tmp3.next != nullptr ? tmp3 = *tmp3.next : tmp3 = koalaNurseList;
    }
    displayEndTime();
}
