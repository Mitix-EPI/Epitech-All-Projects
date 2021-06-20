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
