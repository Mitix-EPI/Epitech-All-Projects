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
    this->filename = "";
}

Picture::Picture(const std::string &file)
{
    this->filename = file;
    this->getPictureFromFile(file);
}

Picture::Picture(const Picture &oldPicture)
{
    this->filename = oldPicture.filename;
    this->data = oldPicture.data;
}

Picture &Picture::operator=(const Picture &oldPicture)
{
    this->filename = oldPicture.filename;
    this->data = oldPicture.data;
    return *this;
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
