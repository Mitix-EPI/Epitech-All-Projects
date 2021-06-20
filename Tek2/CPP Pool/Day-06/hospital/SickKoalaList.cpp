/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *patient) : patient(patient)
{
    next = nullptr;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd(void)
{
    if (this->next == nullptr)
        return true;
    return false;
}

void SickKoalaList::append(SickKoalaList *patient)
{
    SickKoalaList *tmp = this;

    if (!tmp) {
        tmp = patient;
        tmp->next = nullptr;
        return;
    }
    for (; !tmp->isEnd(); tmp = tmp->next);
    tmp->next = patient;
    tmp->next->next = nullptr;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *tmp = this;

    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (!tmp->patient)
            continue;
        if (tmp->patient->getName() == name)
            return tmp->patient;
    }
    return nullptr;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *node)
{
    SickKoalaList *tmp = this;

    if (this == node)
        return this->next;
    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (tmp->next == node) {
            tmp->next = tmp->next->next;
            return this;
        }
    }
    return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *tmp = this;

    if (this->patient->getName() == name)
        return this->next;
    for (; !tmp->isEnd(); tmp = tmp->next) {
        if (!tmp->next->patient)
            continue;
        if (tmp->next->patient != nullptr && tmp->next->patient->getName() == name) {
            tmp->next = tmp->next->next;
            return this;
        }
    }
    return this;
}

SickKoala *SickKoalaList::getContent(void)
{
    return this->patient;
}

SickKoalaList *SickKoalaList::getNext(void)
{
    if (!this->next) {
        return nullptr;
    }
    return this->next;
}

void SickKoalaList::dump(void)
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (!tmp->patient) {
            std::cout << "[nullptr]";
        } else {
            std::cout << tmp->patient->getName();
        }
        std::cout << ", ";
    }
    if (tmp->patient)
        std::cout << tmp->patient->getName();
    std::cout << ".";
    std::cout << std::endl;
}
