/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Logfile
*/

#ifndef LOGFILE_HPP_
#define LOGFILE_HPP_

#define LOGFILE_PATH "plazza.log"

#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <clocale>

class Logfile {
    public:
        static void logFile(std::string);
        static void initLogFile(void);
};

#endif /* !LOGFILE_HPP_ */
