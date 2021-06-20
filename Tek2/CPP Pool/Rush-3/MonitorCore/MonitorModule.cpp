/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** MonitorModule
*/

#include "MonitorModule.hpp"

MonitorModule::MonitorModule(std::string const &name, std::string const &type): _name(name), _type(type), _isShown(true)
{
}

MonitorModule::~MonitorModule()
{
}

std::string MonitorModule::getName(void) const
{
    return _name;
}

std::string MonitorModule::getType(void) const
{
    return _type;
}

void MonitorModule::setType(std::string const &str)
{
    _type = str;
}