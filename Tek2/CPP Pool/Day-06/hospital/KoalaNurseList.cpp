/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse) : nurse(nurse)
{
    next = nullptr;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd(void)
{
    if (this->next == nullptr)
        return true;
    return false;
}

void KoalaNurseList::append(KoalaNurseList *nurse)
{
    KoalaNurseList *tmp = this;

    if (!tmp) {
        tmp = nurse;
        tmp->next = nullptr;
        return;
    }
    for (; !tmp->isEnd(); tmp = tmp->next);
    tmp->next = nurse;
    tmp->next->next = nullptr;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *tmp = this;

    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (!tmp->nurse)
            continue;
        if (tmp->nurse->getID() == id)
            return tmp->nurse;
    }
    return nullptr;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *node)
{
    KoalaNurseList *tmp = this;

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

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *tmp = this;

    if (this->nurse->getID() == id)
        return this->next;
    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (!tmp->next->nurse)
            continue;
        if (tmp->next->nurse->getID() == id) {
            tmp->next = tmp->next->next;
            return this;
        }
    }
    return this;
}

KoalaNurse *KoalaNurseList::getContent(void)
{
    return this->nurse;
}

KoalaNurseList *KoalaNurseList::getNext(void)
{
    if (!this->next) {
        return nullptr;
    }
    return this->next;
}

void KoalaNurseList::dump(void)
{
    KoalaNurseList *tmp = this;

    std::cout << "Nurses: ";
    for (; tmp->isEnd() == false; tmp = tmp->next) {
        if (!tmp->nurse) {
            std::cout << "[nullptr]";
        } else {
            std::cout << tmp->nurse->getID();
        }
        std::cout << ", ";
    }
    if (tmp->nurse)
        std::cout << tmp->nurse->getID();
    std::cout << ".";
    std::cout << std::endl;
}
