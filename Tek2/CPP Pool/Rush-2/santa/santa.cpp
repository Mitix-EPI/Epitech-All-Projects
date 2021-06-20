/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** santa
*/

#include "santa.hpp"

void displayGifts(std::list<std::string> toys)
{
    std::list<std::string> names;
    int index = 0;

    names.push_front("\033[38;5;212mJuanito\033[0m");
    names.push_front("Titouan");
    names.push_front("Mattis");
    names.push_front("Cyril");
    names.push_front("\U0001F436 Mouki \U0001F436");
    srand(time(NULL));
    std::cout << std::endl << "There are " << toys.size() << " gifts today !" << std::endl << std::endl;
    for (std::string toy : toys) {
        index = rand() % 5;
        auto tmp = names.begin();
        std::advance(tmp, index);
        std::cout << "A gift for " << *tmp << " contain \033[1m\033[31m" << toy << " \033[0m";
        if (toy == "Teddy") {
            std::cout << "\U0001F43B" << std::endl;
        } else if (toy == "LittlePony") {
            std::cout << "\U0001F984" << std::endl;
        } else {
            std::cout << "\U0001F308" << std::endl;
        }
    }
}

void parseXml(int ac, char **av)
{
    std::string line;
    std::size_t index;
    std::size_t length;
    std::list<std::string> toys;
    std::string name;

    for (int i = 1; i < ac; i += 1) {
        std::ifstream file(av[i]);
        if (file.fail()) {
            std::cerr << "Error: Can't open file " << av[i] << std::endl;
        }
        while (std::getline(file, line)) {
            if (line.find("<gifts.name>") != -1) {
                index = line.find(">") + 1;
                length = line.length();
                name = line.substr(index, length - 13 - index);
                toys.push_front(name);
            }
        }
        file.close();
    }
    displayGifts(toys);
}

int main(int ac, char **av)
{
    if (ac <= 1) {
        std::cerr << "Invalid input: ./santa <file.xml ...>" << std::endl;
        return (84);
    } else {
        std::cout << "\033[1m\033[32m ___    __    _  _  ____   __       ___  __      __    __  __  ___" << std::endl;
        std::cout << "\033[1m\033[32m/ __)  /__\\  ( \\( )(_  _) /__\\     / __)(  )    /__\\  (  )(  )/ __)" << std::endl;
        std::cout << "\033[1m\033[37m\\__ \\ /(__)\\  )  (   )(  /(__)\\   ( (__  )(__  /(__)\\  )(__)( \\__ \\ " << std::endl;
        std::cout << "\033[1m\033[32m(___/(__)(__)(_)\\_) (__)(__)(__)   \\___)(____)(__)(__)(______)(___/\033[0m" << std::endl;
        parseXml(ac, av);
    }
}
