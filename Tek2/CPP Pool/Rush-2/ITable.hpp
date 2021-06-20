/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "main_santa.hpp"
#include "Object.hpp"

class ITable {
    public:
        ITable() {}
        virtual ~ITable();

        virtual ITable *createTable(void) = 0;

        // Getters
        virtual int getCount(void) const = 0;
        virtual std::array<std::string, 11>look(void) const = 0;
        virtual int countObjectFromType(const std::string type) = 0;
        virtual Object *getObjectFromType(const std::string type) = 0;

        // Methods
        virtual void put(Object *obj) = 0;
        virtual Object *take(const std::string type) = 0;

    protected:
        std::list<Object *> _objects; // 10 MAX
    private:
};

#endif /* !ITABLE_HPP_ */
