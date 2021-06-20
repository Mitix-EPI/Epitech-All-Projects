/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD14M-alexandre.juan
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "Coconut.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();

        int nbFruits(void) const;
        FruitNode *head(void) const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit(void);


        int _max_size;
        FruitNode *next;

    protected:
    private:
};

#endif /* !FRUITBOX_HPP_ */
