/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasTable
*/

#ifndef PAPAXMASTABLE_HPP_
#define PAPAXMASTABLE_HPP_

#include "ITable.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class PapaXmasTable : public ITable {
    public:
        PapaXmasTable(const bool construct = true);
        ~PapaXmasTable();

        // Getters
        int getCount(void) const {return this->_objects.size();};

        std::array<std::string, 11>look(void) const;
        void put(Object *obj);
        Object *take(const std::string type);
        int countObjectFromType(const std::string type);
        Object *getObjectFromType(const std::string type);
        ITable *createTable(void);
    protected:
    private:
};

#endif /* !PAPAXMASTABLE_HPP_ */
