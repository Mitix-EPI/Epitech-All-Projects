/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doc) : doc(doc)
{
    next = nullptr;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd(void)
{
    if (this->next == nullptr)
        return true;
    return false;
}

void KoalaDoctorList::append(KoalaDoctorList *doc)
{
    KoalaDoctorList *tmp = this;

    if (!tmp) {
        tmp = doc;
        tmp->next = nullptr;
        return;
    }
    for (; !tmp->isEnd(); tmp = tmp->next);
    tmp->next = doc;
    tmp->next->next = nullptr;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *tmp = this;

    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (!tmp->doc)
            continue;
        if (tmp->doc->getName() == name)
            return tmp->doc;
    }
    return nullptr;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *node)
{
    KoalaDoctorList *tmp = this;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *tmp = this;

    if (this->doc->getName() == name)
        return this->next;
    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (!tmp->next->doc)
            continue;
        if (tmp->next->doc->getName() == name) {
            tmp->next = tmp->next->next;
            return this;
        }
    }
    return this;
}

KoalaDoctor *KoalaDoctorList::getContent(void)
{
    return this->doc;
}

KoalaDoctorList *KoalaDoctorList::getNext(void)
{
    if (!this->next) {
        return nullptr;
    }
    return this->next;
}

void KoalaDoctorList::dump(void)
{
    KoalaDoctorList *tmp = this;

    std::cout << "Doctors: ";
    for (; !tmp->isEnd(); tmp = tmp->next) {
        if (!tmp->doc) {
            std::cout << "[nullptr]";
        } else {
            std::cout << tmp->doc->getName();
        }
        std::cout << ", ";
    }
    if (tmp->doc)
        std::cout << tmp->doc->getName();
    std::cout << ".";
    std::cout << std::endl;
}
