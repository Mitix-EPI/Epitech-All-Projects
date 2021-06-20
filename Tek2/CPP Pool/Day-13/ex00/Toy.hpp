/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        typedef enum ToyType {
            ALIEN,
            BASIC_TOY
        } ToyType;

        Toy();
        Toy(ToyType toyType, const std::string &name, const std::string &filename);
        ~Toy();


        ToyType getType(void) const { return this->type; }
        std::string getName(void) const { return this->name; }
        std::string getAscii(void) const { return this->picture.data; }

        void setName(const std::string &name) { this->name = name; }
        bool setAscii(const std::string &filename) { return this->picture.getPictureFromFile(filename); };


    protected:
        Picture picture;
        ToyType type;
        std::string name;
    private:
};

#endif /* !TOY_HPP_ */