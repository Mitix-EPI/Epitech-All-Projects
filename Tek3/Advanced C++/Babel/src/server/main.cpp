/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** main
*/

#include <iostream>
#include <asio.hpp>
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "server/AServer.hpp"
#include "server/Server.hpp"
#include "commons/Connection.hpp"
#include "server/database/database.hpp"
#include "commons/exceptions.hpp"
#include "commons/users.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "./babel_client <port>" << std::endl;
        return 84;
    }
    try {
        Server server(std::atoi(av[1]));
        server.Start();

        while (1)
        {
            server.Update();
        }
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}