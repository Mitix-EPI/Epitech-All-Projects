/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** PapaXmasConveyorBelt
*/

#include "PapaXmasConveyorBelt.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    this->_object = nullptr;
    this->_box = true;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
    if (this->_object != nullptr)
        delete this->_object;
}

IConveyorBelt *PapaXmasConveyorBelt::createConveyorBelt(void)
{
    IConveyorBelt *res = new PapaXmasConveyorBelt();
    return res;
}

void PapaXmasConveyorBelt::in(void)
{
    if (this->getObject() != nullptr) {
        raise("Error: ConveyorBelt has already an Object");
        return;
    }
    if (this->getBool()) {
        this->_object = new Box();
    } else {
        this->_object = new GiftPaper();
    }
    this->_box = !this->getBool();
}

void recursiveDtorConveyor(Object *obj)
{
    if (obj != nullptr && obj->getObject() != nullptr)
        recursiveDtorConveyor(obj->getObject());
    if (obj != nullptr)
        delete obj;
}

void PapaXmasConveyorBelt::out(void)
{
    std::cout << "OUT : " << *this->_object;
    if (this->getObject() == nullptr) {
        raise("Error: You can't give a null Object to Santa !!");
        return;
    }
    recursiveDtorConveyor(this->_object);
    this->_object = nullptr;
}

Object *PapaXmasConveyorBelt::takeObject(void)
{
    Object *tmp = this->getObject();

    this->_object = nullptr;
    return tmp;
}

void PapaXmasConveyorBelt::putObject(Object *obj)
{
    if (this->_object == nullptr) {
        this->_object = new Object(obj);
        return;
    } else
        raise("Error: The ConveyorBelt already contains an object");
}

void PapaXmasConveyorBelt::trash()
{
    if (this->_object != nullptr) {
        delete this->_object;
        this->_object = nullptr;
    } else
        raise("Error: Cannot send a null object to the trash !");
}
