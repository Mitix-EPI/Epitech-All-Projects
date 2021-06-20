/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->picture = new Picture;
    this->type = BASIC_TOY;
    this->name = "toy";
    this->error = Error();
}

Toy::Toy(const ToyType &type, const std::string name, const std::string filename)
{
    this->picture = new Picture(filename);
    this->type = type;
    this->name = name;
    this->error = Error();
}

Toy::Toy(const Toy &oldToy)
{
    this->picture = new Picture;
    this->name = oldToy.name;
    this->type = oldToy.type;
    if (oldToy.picture) {
        this->picture->data = oldToy.picture->data;
    } else {
        this->picture->data = "";
    }
    this->error = oldToy.error;
    this->picture->filename = oldToy.picture->filename;
}

Toy &Toy::operator=(const Toy &oldToy)
{
    this->picture = new Picture;
    this->name = oldToy.name;
    this->type = oldToy.type;
    if (oldToy.picture) {
        this->picture->data = oldToy.picture->data;
    } else {
        this->picture->data = "";
    }
    this->error = oldToy.error;
    this->picture->filename = oldToy.picture->filename;
    return *this;
}

bool Toy::setAscii(const std::string &filename)
{
    if (!this->picture->getPictureFromFile(filename)) {
        this->error.setType(this->error.PICTURE);
        this->error.setWhat("bad new illustration");
        this->error.setWhere("setAscii");
        return false;
    } else {
        return true;
    }
}

bool Toy::speak(const std::string statement)
{
    std::cout << this->getName() << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(const std::string statement)
{
    if (this->type == BUZZ) {
        std::cout << "BUZZ: " << this->getName() << " senorita" << " \"" << statement << "\" senorita" << std::endl;
        return true;
    } else {
        this->error.setType(this->error.SPEAK);
        this->error.setWhat("wrong mode");
        this->error.setWhere("speak_es");
        return false;
    }
}

std::ostream &operator<<(std::ostream &s, const Toy &toy)
{
    s << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return s;
}

Toy &operator<<(Toy &toy, const std::string &str)
{
    toy.setData(str);
    return toy;
}

Toy::~Toy()
{
}
