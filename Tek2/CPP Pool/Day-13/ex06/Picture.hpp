/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Picture {
    public:
        Picture();
        Picture(const std::string &file);
        Picture &operator=(const Picture &oldPicture);
        Picture(const Picture &oldPicture);
        ~Picture();

        bool getPictureFromFile(const std::string &file);

        std::string data;
        std::string filename;
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
