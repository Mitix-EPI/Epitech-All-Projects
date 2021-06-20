/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** TableRand
*/

#include "TableRand.hpp"

TableRand::TableRand(): PapaXmasTable(false)
{
    srand(time(NULL));
    int numberObjects = rand() % 9;
    int classCreated = 0;

    for (int i = 0; i < numberObjects; i++) {
        classCreated = rand() % 4;
        switch (classCreated) {
            case 0:
                this->_objects.push_front(new Teddy("Ted"));
                break;
            case 1:
                this->_objects.push_front(new LittlePony("Pony"));
                break;
            case 2:
                this->_objects.push_front(new Box());
                break;
            case 3:
                this->_objects.push_front(new GiftPaper());
                break;
            default:
                break;
        }
    }

}

TableRand::~TableRand()
{
}
