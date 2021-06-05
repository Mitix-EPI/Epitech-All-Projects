/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include "Parser.hpp"
#include "Circuit.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <functional>
#include <utility> // std::pair
#include <csignal>

class Shell {
    public:
        Shell(Circuit *circuit);
        ~Shell();

        void displayPrompt(void) const;
        std::istream &getLineCommand(void);
        void executeCommand(void);

        // MAP FUNCTIONS
        void exit(void);
        void display(void);
        void simulate(void);
        void loop(void);
        void dump(void);
        void clear(void);

        // GETTERS

        std::string getCommand(void) const { return (this->_command); }
        const std::string getPrompt(void) const { return (this->_prompt); }
        bool isLoop(void) const { return (this->_loop); }

        static bool loopExit;

    protected:
        bool _isASetter(void);
        void _fillMapFunctions(void);

    private:
        std::string _command;

        std::unordered_map<std::string, std::function<void(void)>> _mapFunctions;

        const std::vector<std::string> _allowedMethods = {"display", "simulate", "exit", "loop", "dump", "clear"};
        const std::string _prompt = "> ";

        Circuit *_circuit;

        bool _loop;
};

void sigintHandler(int signum);
void loopHandling(int signum);

#endif /* !SHELL_HPP_ */
