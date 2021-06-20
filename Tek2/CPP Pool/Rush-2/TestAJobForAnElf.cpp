/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** TestAJobForAnElf
*/

#include "TableRand.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasElf.hpp"
#include "ConveyorBeltRand.hpp"

int main(void)
{
    PapaXmasElf *elf = new PapaXmasElf();
    TableRand *table = new TableRand();
    ConveyorBeltRand *conveyor = new ConveyorBeltRand();
    std::cout << "There is: " << table->getCount() << " element(s) on the table." << std::endl;
    for (int i = 0; i < table->getCount(); i++)
    {
        std::cout << table->look()[i] << std::endl;
    }
    elf->makeGift(table, conveyor);
    std::cout << "There is: " << table->getCount() << " element(s) on the table." << std::endl;
    for (int i = 0; i < table->getCount(); i++)
    {
        std::cout << table->look()[i] << std::endl;
    }

    delete elf;
    delete table;
    delete conveyor;
}
