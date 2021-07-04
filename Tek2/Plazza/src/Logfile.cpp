/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Logfile
*/

#include "Logfile.hpp"

void Logfile::initLogFile(void)
{
    std::ofstream file;
    file.open(LOGFILE_PATH, std::ios::out | std::ios::trunc);
    if (file.fail())
        throw std::ios_base::failure(std::strerror(errno));
    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);
    file << "Plazza initializing ..." << std::endl;
    file.close();
}

void Logfile::logFile(std::string message)
{
    std::ofstream file;
    file.open(LOGFILE_PATH, std::ios::out | std::ios::app);
    if (file.fail())
        throw std::ios_base::failure(std::strerror(errno));
    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);
    file << message << std::endl;
    file.close();
}
