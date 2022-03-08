/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#include "commons/common.h"
#include "commons/Package.hpp"
#include "client/Client.hpp"
#include "client/AClient.hpp"
#include "ui/WindowManager.hpp"
#include <iostream>
#include <portaudio.h>
#include "commons/users.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cout << "./babel_client <address> <port>" << std::endl;
        return 84;
    }
    try {
        Client c;
        c.Connect(av[1], std::atoi(av[2]));
        bool Quit = false;
        bool first = true;
        std::cout << std::boolalpha;
        GUI::WindowManager w(ac, av, &c);
        while (!Quit && w.isOpen()) {
            w.update();
            if (c.IsConnected()) {
                c.update();
            } else {
                std::cout << "Server Down" << std::endl;
                Quit = true;
            }
        }
        c.disconnect();
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}