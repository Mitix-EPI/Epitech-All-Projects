/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** DisplayLog
*/

#include "DisplayLog.hpp"

std::vector<std::string> getAllLog(void)
{
    std::vector<std::string> res;
    std::string tmpString;
    std::ifstream plazzaLog(LOG_FILE);

    while (std::getline(plazzaLog, tmpString))
        res.push_back(tmpString);
    plazzaLog.close();
    return res;
}

std::vector<std::string> getDisplayLog(void)
{
    std::vector<std::string> res;
    size_t calc = 0;
    std::vector<std::string> allLines = getAllLog();

    if (allLines.size() < LOG_LINES_MAX)
        for (size_t i = 0; i < LOG_LINES_MAX - allLines.size(); i++, res.push_back(""));

    if (allLines.size() >= LOG_LINES_MAX)
        calc = allLines.size() - LOG_LINES_MAX;
    for (size_t i = calc; i < allLines.size(); i++) {
        res.push_back(allLines.at(i));
    }
    return res;
}
