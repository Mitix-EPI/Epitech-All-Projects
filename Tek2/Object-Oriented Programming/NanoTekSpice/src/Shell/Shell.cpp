/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Shell
*/

#include "Shell.hpp"

bool Shell::loopExit = true;

Shell::Shell(Circuit *circuit)
{
    this->_command = "";
    this->_loop = true;
    Shell::loopExit = true;
    this->_circuit = circuit;

    this->_fillMapFunctions();
}

void Shell::_fillMapFunctions(void)
{
    this->_mapFunctions["display"] = [&]{ this->display(); };
    this->_mapFunctions["simulate"] = [&]{ this->simulate(); };
    this->_mapFunctions["exit"] = [&]{ this->exit(); };
    this->_mapFunctions["loop"] = [&]{ this->loop(); };
    this->_mapFunctions["dump"] = [&]{ this->dump(); };
    this->_mapFunctions["clear"] = [&]{ this->clear(); };
}

void Shell::clear(void)
{
    std::cout << "\033[2J\033[1;1H";
}

void Shell::exit(void)
{
    this->_loop = false;
}

void Shell::display(void)
{
    this->_circuit->display();
}

void Shell::simulate(void)
{
    this->_circuit->simulate();
}

void sigintHandler(int signum)
{
    (void) signum;
}

void loopHandling(int signum)
{
    (void) signum;
    Shell::loopExit = false;
}

void Shell::loop(void)
{
    Shell::loopExit = true;
    signal(SIGINT, loopHandling);
    while (Shell::loopExit) {
        this->_circuit->simulate();
        this->_circuit->display();
    }
    signal(SIGINT, sigintHandler);
    Shell::loopExit = true;
}

void Shell::dump(void)
{
    this->_circuit->dump();
}

void Shell::displayPrompt(void) const
{
    std::cout << this->_prompt;
}

std::istream &Shell::getLineCommand(void)
{
    return std::getline(std::cin, this->_command);
}

void Shell::executeCommand(void)
{
    this->_command = Parser::parseLine(this->_command);
    if (this->_isASetter()) {
        std::string name;
        nts::Tristate value;
        std::size_t pos = this->_command.find_last_of('=');
        std::string val;

        name = this->_command.substr(0, pos);
        val = this->_command.substr(pos + 1);

        if (val == "U") {
            value = nts::Tristate::UNDEFINED;
        } else if (val == "1") {
            value = nts::Tristate::TRUE;
        } else if (val == "0") {
            value = nts::Tristate::FALSE;
        } else {
            std::cerr << "Error: Wrong setter value" << std::endl;
            return;
        }
        this->_circuit->setValue(name, value);

    } else if (std::find(this->_allowedMethods.begin(), this->_allowedMethods.end(), this->_command) != this->_allowedMethods.end()) {
        this->_mapFunctions[this->_command]();
    } else {
        if (!this->_command.empty()) {
            std::cerr << "Error: Invalid command." << std::endl;
        }
    }
}

bool Shell::_isASetter(void)
{
    if (this->_command.find_last_of('=') != std::string::npos) {
        return (true);
    }
    return (false);
}

Shell::~Shell()
{
}
