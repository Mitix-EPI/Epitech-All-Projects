/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include "Toy.hpp"

class ToyStory {
    public:
        ToyStory();
        ~ToyStory();

        static int checkPictureError(Toy toy);
        static void tellMeAStory(std::string filename, Toy toy1, bool(Toy::*func1)(const std::string statement), Toy toy2, bool(Toy::*func2)(const std::string statement));
        static bool toyTime(Toy toy, std::ifstream *file, std::string line, bool(Toy::*func)(const std::string statement));
        static bool checkSpeakError(Toy toy, bool notError);

    protected:
    private:
};

#endif /* !TOYSTORY_HPP_ */
