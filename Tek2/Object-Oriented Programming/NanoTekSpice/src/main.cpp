/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** main
*/
#include <csignal>

#include "ComponentFactory.hpp"
#include "nanoTekSpice.hpp"
#include "Components.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"
#include "Shell.hpp"


int displayHelp(void)
{
    std::cout << "N a n o  T e k  S p i c e" << std::endl << std::endl;
    std::cout << "Launch program:" << std::endl;
    std::cout << "\t- ./nanotekspice -h : Display help" << std::endl;
    std::cout << "\t- ./nanotekspice [filepath] : Launch program" << std::endl << std::endl;
    std::cout << "Commands inside program:" << std::endl;
    std::cout << "\t- simulate : Execute your electrical montage in 1 tick" << std::endl;
    std::cout << "\t- display : Display values of your pins at actual tick" << std::endl;
    std::cout << "\t- component=pin : Change linked pin of component" << std::endl;
    return 0;
}

int launch_program(char *filename)
{
    Parser parser(filename);
    Circuit circuit(parser);
    Shell sh(&circuit);

    signal(SIGINT, sigintHandler);

    while (sh.isLoop()) {
        sh.displayPrompt();
        if (!sh.getLineCommand()) {
            sh.exit();
            break;
        }
        try {
            sh.executeCommand();
        } catch (InvalidPin const &e) {
            std::cerr << e.what() << std::endl;
        } catch (InvalidName const &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Not enough arguments." << std::endl << "Please type ./nanotekspice -h for help" << std::endl;
        return (84);
    } else {
        if (av[1][0] == '-' && av[1][1] == 'h')
            return displayHelp();
        return launch_program(av[1]);
    }
}
