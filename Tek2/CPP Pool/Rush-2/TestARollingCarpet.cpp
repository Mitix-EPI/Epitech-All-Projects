/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** TestARollingCarpet
*/

#include "main_santa.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasTable.hpp"

void MyUnitTest(PapaXmasTable *table, PapaXmasConveyorBelt *conveyorBelt)
{
    Object *wrap;
    Object *gift;
    Object *toy;

    conveyorBelt->in();
    wrap = conveyorBelt->takeObject();
    table->put(wrap);
    conveyorBelt->in();
    wrap = conveyorBelt->takeObject();
    table->put(wrap);
    toy = table->take(TOY);
    wrap = table->take(BOX);
    gift = table->take(PAPER);
    ((Wrap *)wrap)->wrapMeThat(toy);
    ((Wrap *)gift)->wrapMeThat(wrap);
    conveyorBelt->putObject(gift);
    delete gift;
}

/*int main(void)
{
    PapaXmasTable *table = new PapaXmasTable();
    PapaXmasConveyorBelt *conveyorBelt = new PapaXmasConveyorBelt();

    //Should output 2 toys title
    std::array<std::string, 11> string_array = table->look();
    for (int i = 0; i < table->getCount(); i++)
        std::cout << string_array[i] << std::endl;

    MyUnitTest(table, conveyorBelt);

    //Should output type and name of gift 2 times
    std::cout << *conveyorBelt->getObject();

    //Should output nullptr
    conveyorBelt->out();
    if (conveyorBelt->getObject() == nullptr) {
        std::cout << "Coveyor Empty !" << std::endl;
    } else {
        std::cout << "Error: Conveyor is not empty (should)" << std::endl;
    }

    //should output only 1 toy title
    std::array<std::string, 11> string_array2 = table->look();
    for (int i = 0; i < table->getCount(); i++)
        std::cout << string_array2[i] << std::endl;

    delete conveyorBelt;
    delete table;
    return (0);
}*/
