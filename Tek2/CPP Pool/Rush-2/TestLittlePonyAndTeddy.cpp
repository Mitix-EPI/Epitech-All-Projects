/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** TestLittlePonyAndTeddy
*/

#include "main_santa.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"

Object **MyUnitTests(void)
{
    Object **tab_object = new (Object *[2]);
    Object *pony = new LittlePony("happy pony");
    Object *teddy = new Teddy("cuddles");

    tab_object[0] = pony;
    tab_object[1] = teddy;
    return tab_object;
}

/*int main(void)
{
    Object **res = MyUnitTests();

    std::cout << *(res[0]);
    std::cout << res[0]->getName() << " -> Created !" << std::endl;

    // Should return
    // I'm happy pony and I am a Little Pony
    // happy pony -> Created !

    ///////////////////////////////////////////////////////////////

    std::cout << std::endl;
    std::cout << *(res[1]);
    std::cout << res[1]->getName() << " -> Created !" << std::endl;

    // Should return
    // I'm cuddles and I am a Teddy
    // cuddles -> Created !
    delete res[0];
    delete res[1];
    delete []res;
}*/
