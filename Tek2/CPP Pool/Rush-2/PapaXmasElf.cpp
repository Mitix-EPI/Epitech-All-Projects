/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** PapaXmasElf
*/

#include "PapaXmasElf.hpp"

PapaXmasElf::PapaXmasElf()
{
    this->_obj = nullptr;
}

PapaXmasElf::~PapaXmasElf()
{
}

void PapaXmasElf::trashButton(IConveyorBelt *conveyor)
{
    conveyor->trash();
}

bool PapaXmasElf::getComponent(ITable *table, IConveyorBelt *conveyor)
{
    int gift = table->countObjectFromType(TOY);
    int box = table->countObjectFromType(BOX);
    int giftPaper = table->countObjectFromType(PAPER);
    int size = 0;

    if (gift == 0)
        return false;
    while (box == 0) {
        size = table->getCount();
        if (size >= 10)
            this->trashUselessObjectOnTable(table, conveyor, PAPER);
        this->pressInButton(conveyor);
        this->takeObjectFromConveyorBelt(conveyor);
        this->putObjectInTable(table);
        box = table->countObjectFromType(BOX);
    }
    while (giftPaper == 0) {
        size = table->getCount();
        if (size >= 10)
            this->trashUselessObjectOnTable(table, conveyor, BOX);
        this->pressInButton(conveyor);
        this->takeObjectFromConveyorBelt(conveyor);
        this->putObjectInTable(table);
        giftPaper = table->countObjectFromType(PAPER);
    }
    return true;
}

void PapaXmasElf::makeGift(ITable *table, IConveyorBelt *conveyor)
{
    while (getComponent(table, conveyor) == true) {

        Toy *toy = (Toy *)table->getObjectFromType(TOY);
        toy->isTaken();
        this->takeObjectFromTable(table, TOY);
        Object *box = table->getObjectFromType(BOX);
        Wrap *box1 = (Wrap *)box;
        if (!box->getOpen())
            this->openWrap(box1);
        this->wrapThat(box1);
        this->closeWrap(box1);
        this->takeObjectFromTable(table, BOX);
        this->takeWrap();
        Object *gift_paper = table->getObjectFromType(PAPER);
        Wrap *paper = (Wrap *)gift_paper;
        this->wrapThat(paper);
        this->takeObjectFromTable(table, PAPER);
        this->putObjectInConveyorBelt(conveyor);
        this->pushOutButton(conveyor);
    }
    std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
}

void PapaXmasElf::trashUselessObjectOnTable(ITable *table, IConveyorBelt *conveyor, std::string type)
{
    std::string remp;
    this->takeObjectFromTable(table, type);
    if (!this->getObject()) {
        std::cout << "Attention, il n'y a pas de truc de ce type dans la liste" << std::endl;
        return;
    }
    this->putObjectInConveyorBelt(conveyor);
    this->trashButton(conveyor);
}

void PapaXmasElf::openWrap(Wrap *wrap)
{
    wrap->openMe();
}

void PapaXmasElf::closeWrap(Wrap *wrap)
{
    wrap->closeMe();
}

void PapaXmasElf::wrapThat(Wrap *wrap)
{
    if (wrap == nullptr) {
        raise("Error: you cannot wrap in this null object");
        return;
    }
    wrap->wrapMeThat(this->_obj);
    std::cout << "tuuuut tuuut tuut" << std::endl;
    this->_obj = nullptr;
}

std::array<std::string, 11> PapaXmasElf::lookTable(ITable *table)
{
    return table->look();
}

// Takes
void PapaXmasElf::takeToy(Toy *toy)
{
    if (this->getObject()) {
        raise("Error : Your hands are full!");
        return;
    }
    toy->isTaken();
    this->_obj = toy;
}

void PapaXmasElf::takeWrap()
{
    std::cout << "whisles while working" << std::endl;
}

void PapaXmasElf::takeObjectFromTable(ITable *table, std::string type)
{
    if (this->_obj) {
        raise("Error:Your hand are full!");
        return;
    }
    this->_obj = table->take(type);
}

void PapaXmasElf::takeObjectFromConveyorBelt(IConveyorBelt *conveyor)
{
    if (this->_obj) {
        raise("Error: Your hand are full!");
        return;
    }
    this->takeWrap();
    this->_obj = conveyor->takeObject();
}

// Puts
void PapaXmasElf::putObjectInTable(ITable * table)
{
    table->put(this->getObject());
    this->_obj = nullptr;
}

void PapaXmasElf::putObjectInConveyorBelt(IConveyorBelt *conveyor)
{
    conveyor->putObject(this->getObject());
    delete this->_obj;
    this->_obj = nullptr;
}

// Buttons
void PapaXmasElf::pressInButton(IConveyorBelt *conveyor)
{
    conveyor->in();
}

void PapaXmasElf::pushOutButton(IConveyorBelt *conveyor)
{
    conveyor->out();
}
