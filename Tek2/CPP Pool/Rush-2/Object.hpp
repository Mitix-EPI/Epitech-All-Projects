/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-cyril.grosjean
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "main_santa.hpp"

#define TOY (std::string) "Toy"
#define TED (std::string) "Teddy"
#define PONY (std::string) "Little Pony"
#define PAPER (std::string) "Gift Paper"
#define BOX (std::string) "Box"
#define WRAP (std::string) "Wrap"

class Object {
    public:
        Object(std::string &name, const std::string &type);
        Object() {}
        virtual ~Object();
        Object(const Object *object);
        // Getters
        const std::string &getName() const { return this->_name;}
        const std::string &getType() const { return this->_type;}
        bool getOpen(void) const { return this->_open; }
        Object *getObject(void) const { return this->_obj; }

    protected:
        std::string _name;
        std::string _type;
        Object *_obj;
        bool _open;
    private:
};

std::ostream &operator<<(std::ostream &s, Object &obj);

#endif /* !OBJECT_HPP_ */
