/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Tasks
*/

#include "Tasks.hpp"

Tasks::Tasks(std::string const &name, std::string const &type):  MonitorModule(name, type)
{

}

Tasks::~Tasks()
{

}

std::vector<float> Tasks::getAverage(void)
{
    std::ifstream file("/proc/loadavg");
    std::stringstream buffer;
    std::string model = "";
    std::vector<float> res;
    float tmp = 0.0;

    if (!file.is_open())
        exit (84);
    std::string str;
    getline(file, str);
    buffer << str;
    buffer >> tmp;
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find(" "), str.size() - 1);
    buffer << str;
    buffer >> tmp;
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find(" "), str.size() - 1);
    buffer << str;
    buffer >> tmp;
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find(" "), str.size() - 1);
    buffer << str;
    buffer >> tmp;
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find("/") + 1, str.size() - 1);
    str = str.substr(0, str.find(" "));
    res.push_back(std::stof(str));
    buffer.clear();
    file.close();
    return res;
}

void Tasks::updateData()
{

}

void Tasks::setNumProc(void)
{
}
