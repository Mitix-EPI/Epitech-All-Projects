/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** DisplayLog
*/

#ifndef DISPLAYLOG_HPP_
#define DISPLAYLOG_HPP_

#define LOG_LINES_MAX 10
#define LOG_FILE "plazza.log"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

std::vector<std::string> getAllLog(void);
std::vector<std::string> getDisplayLog(void);

#endif /* !DISPLAYLOG_HPP_ */
