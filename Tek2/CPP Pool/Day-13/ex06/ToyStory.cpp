/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

int ToyStory::checkPictureError(Toy toy)
{
    toy.setAscii(toy.getPicture()->filename);
    if (toy.getAscii() == "ERROR" || toy.getLastError().type == Toy::Error::PICTURE) {
        auto error = toy.getLastError();
        std::cout << error._where << ": " << error._what << std::endl;
        return false;
    } else {
        std::cout << toy.getAscii() << std::endl;;
        return true;
    }
}

bool ToyStory::checkSpeakError(Toy toy, bool notError)
{
    if (!notError) {
        auto error = toy.getLastError();
        std::cout << error._where << ": " << error._what << std::endl;
        return false;
    } else {
        return true;
    }
}

bool ToyStory::toyTime(Toy toy, std::ifstream *file, std::string line, bool(Toy::*func)(const std::string statement))
{
    if (line.find("picture:") != std::string::npos) {
        std::string filename = line.substr(line.find(":") + 1);
        toy.setAscii(filename);
        toy.getPicture()->filename = filename;
        int boolean = checkPictureError(toy);
        if (boolean == false)
            return false;
        if (!std::getline(*file, line))
            return false;
        boolean = (toy.*func)(line);
        return checkSpeakError(toy, boolean);
    } else {
        int boolean = (toy.*func)(line);
        return checkSpeakError(toy, boolean);
    }
}

void ToyStory::tellMeAStory(std::string filename, Toy toy1, bool(Toy::*func1)(const std::string statement), Toy toy2, bool(Toy::*func2)(const std::string statement))
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        file.close();
        std::cout << "Bad Story" << std::endl;
        return;
    } else {
        if (checkPictureError(toy1) == false) {
            file.close();
            return;
        }
        if (checkPictureError(toy2) == false) {
            file.close();
            return;
        }
        while (std::getline(file, line)) {
            if (!toyTime(toy1, &file, line, func1)) {
                return;
            }
            if (!std::getline(file, line))
                return;
            if (!toyTime(toy2, &file, line, func2)) {
                return;
            }
        }
    }
}
