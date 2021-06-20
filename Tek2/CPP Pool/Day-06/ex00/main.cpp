/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** main
*/

#include "mycat.hpp"

int main(int ac, char **av)
{
    if (argError(ac))
        return 84;

    for (int i = 1; i < ac; i++) {
        std::ifstream file(av[i]);
        if (!file.is_open()) {
            std::cerr << "my_cat: " << av[i] << ": No such file or directory" << std::endl;
        } else {
            char content = file.get();
            while (file.good()) {
                std::cout << content;
                content = file.get();
            }
            file.close();
        }
    }
    return 0;
}
