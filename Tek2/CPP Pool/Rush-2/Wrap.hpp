/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "main_santa.hpp"
#include "Object.hpp"

class Wrap : public Object {
    public:
        Wrap() { _type = WRAP; _name = "WRAP"; }
        Wrap(std::string &name, const std::string &type = WRAP);
        ~Wrap();

        // Getters
        bool getOpen(void) const { return this->_open; }
        Object *getObject(void) const { return this->_obj; }

        bool isAToy(Object *newObject);
        void wrapMeThat(Object *newObj);
        void closeMe(void);
        void openMe(void);

    protected:
    private:
};

#endif /* !WRAP_HPP_ */
