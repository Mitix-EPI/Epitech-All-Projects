/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable(const bool construct)
{
    if (construct) {
        Object *ted = new Teddy("Richard");
        Object *pony = new LittlePony("Juanita");

        this->_objects.push_front(ted);
        this->_objects.push_front(pony);
    }
}

PapaXmasTable::~PapaXmasTable()
{
    for (Object *tmp : this->_objects) {
        if (tmp)
            delete tmp;
    }
}

std::array<std::string, 11>PapaXmasTable::look(void) const
{
    std::array<std::string, 11> res;
    int i = 0;

    for (Object *tmp : this->_objects) {
        res[i] = tmp->getName();
        i++;
    }
    return res;
}

void PapaXmasTable::put(Object *object)
{
    if (this->_objects.size() >= 10) {
        raise("Error: Not enough place on the table (Table will broke !!)");
    } else
        this->_objects.push_front(object);
}

Object *PapaXmasTable::take(const std::string type)
{
    Object *obj = nullptr;

    for (Object *tmp : this->_objects) {
        if (tmp->getType().compare(type) == 0 || (type == TOY && (tmp->getType() == TED || tmp->getType() == PONY))) {
            obj = tmp;
            this->_objects.remove(tmp);
            return (obj);
        }
    }
    return (obj);
}

int PapaXmasTable::countObjectFromType(std::string type)
{
    int count = 0;

    for (Object *tmp : this->_objects) {
        if (tmp->getType().compare(type) == 0 || (type == TOY && (tmp->getType() == TED || tmp->getType() == PONY))) {
            count++;
        }
    }
    return (count);
}

ITable *PapaXmasTable::createTable(void)
{
    ITable *table = new PapaXmasTable();
    return (table);
}

Object *PapaXmasTable::getObjectFromType(const std::string type)
{
    Object *obj = nullptr;

    for (Object *tmp : this->_objects) {
        if (tmp->getType().compare(type) == 0 || (type == TOY && (tmp->getType() == TED || tmp->getType() == PONY))) {
            obj = tmp;
            return (obj);
        }
    }
    return (obj);
}
