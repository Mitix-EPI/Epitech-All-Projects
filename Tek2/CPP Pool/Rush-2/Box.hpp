/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "main_santa.hpp"
#include "Wrap.hpp"

class Box : public Wrap {
    public:
        Box(std::string name = "Box", const std::string &type = BOX);
        ~Box();

    protected:
    private:
};

#endif /* !BOX_HPP_ */
