/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-alexandre.juan
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _max_size(size)
{
    this->next = nullptr;
}

FruitBox::~FruitBox()
{
}

bool FruitBox::putFruit(Fruit *f)
{
    if (this->nbFruits() >= this->_max_size || f == nullptr)
        return false;

    FruitNode *tmp = this->next;
    if (!tmp) {
        this->next = new FruitNode;
        this->next->fruit = f;
        this->next->next = nullptr;
        return true;
    }
    if (tmp->fruit == f)
        return false;
    for (; tmp->next != nullptr; tmp = tmp->next) {
        if (tmp->fruit == f)
            return false;
    }
    tmp->next = new FruitNode;
    tmp->next->fruit = f;
    tmp->next->next = nullptr;
    return true;
}

FruitNode *FruitBox::head(void)
{
    return this->next;
}

int FruitBox::nbFruits()
{
    if (this->next == nullptr)
        return (0);
    int count = 0;
    for (FruitNode *ptr = this->next; ptr; ptr = ptr->next)
        count++;
    return (count);
}

Fruit *FruitBox::pickFruit(void)
{
    FruitNode *tmp = this->next;
    if (!tmp)
        return nullptr;
    this->next = tmp->next;
    return tmp->fruit;
}
