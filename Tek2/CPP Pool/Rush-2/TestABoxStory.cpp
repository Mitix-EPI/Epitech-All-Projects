/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** TestABoxStory
*/

#include "main_santa.hpp"
#include "Wrap.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"

Object *MyUnitTests(Object **objects)
{
    // wrap "BOX" -> teddy "TOY"
    // wrap2 "GIFTPAPER" -> BOX

    Wrap *wrap = (Wrap *)(objects[1]);
    wrap->wrapMeThat(objects[0]);
    Wrap *wrap2 = (Wrap *)(objects[2]);
    wrap2->wrapMeThat(wrap);
    return (wrap2);
}

/*int main(void)
{
    Object **args = new(Object *[3]);
    Object *ted1 = new Teddy("TEDx");
    Object *box1 = new Box();
    Object *paper = new GiftPaper();
    args[0] = ted1;
    args[1] = box1;
    args[2] = paper;

    Object *res = MyUnitTests(args);

    Wrap *wrap = (Wrap *)res;
    if (wrap->getType() == PAPER) {
        std::cout << "It is a GiftPaper on" << std::endl;
    } else {
        std::cerr << "Error: No GiftPaper in first" << std::endl;
        return 84;
    }
    Wrap *wrap2 = (Wrap *)wrap->getObject();
    if (wrap2->getType() == BOX) {
        std::cout << "a Box which contains" << std::endl;
    } else {
        std::cerr << "Error: No Box in second" << std::endl;
        return 84;
    }
    Object *ted = wrap2->getObject();
    if (ted->getType() == TED) {
        std::cout << "a Teddy !!! Merry Christmas !!!" << std::endl;
    } else {
        std::cerr << "Error: No Teddy inside" << std::endl;
        return 84;
    }
    std::cout << *ted;

    delete args[2];
    delete []args;
}*/
