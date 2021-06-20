/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "main_santa.hpp"
#include "Wrap.hpp"

class GiftPaper : public Wrap {
    public:
        GiftPaper(std::string name = "Gift Paper", const std::string &type = PAPER);
        ~GiftPaper();

    protected:
    private:
};

#endif /* !GIFTPAPER_HPP_ */
