/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-alexandre.juan
** File description:
** LittleHand
*/

#include "LittleHand.hpp"
#include "Lemon.hpp"
#include "Banana.hpp"
#include "Lime.hpp"
#include <stdio.h>
#include <string.h>

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitBox res(unsorted.nbFruits());

    for (Fruit *f = nullptr; (f = unsorted.pickFruit()) != nullptr;)
        res.putFruit(f);
    FruitNode *tmp = res.next;
    for (; tmp; tmp = tmp->next) {
        if (tmp->fruit->getName() == "banana" && tmp->fruit->getVitamins() == 5) {
            if (bananas.putFruit(tmp->fruit) == false)
                unsorted.putFruit(tmp->fruit);
        } else if (tmp->fruit->getName() == "lime" && tmp->fruit->getVitamins() == 2) {
            if (limes.putFruit(tmp->fruit) == false)
                unsorted.putFruit(tmp->fruit);
        } else if (tmp->fruit->getName() == "lemon" && tmp->fruit->getVitamins() == 3) {
            if (lemons.putFruit(tmp->fruit) == false)
                unsorted.putFruit(tmp->fruit);
        } else {
            unsorted.putFruit(tmp->fruit);
        }
    }
}

FruitBox * const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
    int count = 0;
    if (!coconuts)
        return nullptr;
    FruitBox **res = new FruitBox*[2];
    FruitBox **tmp = nullptr;
    res[0] = nullptr;
    res[1] = nullptr;
    if (coconuts[0]) {
        res[0] = new FruitBox(6);
    }
    for (int i = 0, j = 0; coconuts[i]; i++) {
        if (count >= 6) {
            count = 0;
            j++;
            FruitBox **tmp = new FruitBox*[j + 2];
            memcpy(tmp, res, sizeof(FruitBox *) * (j + 2));
            tmp[j] = new FruitBox(6);
            tmp[j + 1] = nullptr;
            delete []res;
            res = tmp;
        }
        if (coconuts[i]) {
            res[j]->putFruit(new Coconut(*coconuts[i]));
            count++;
        }
    }
    if (tmp)
        delete []tmp;
    return res;
}

