/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    this->getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        this->data = "ERROR";
        file.close();
        return false;
    } else {
        std::stringstream buffer;
        buffer << file.rdbuf();
        this->data = buffer.str();
        file.close();
        return true;
    }
}

Picture::~Picture()
{
}
