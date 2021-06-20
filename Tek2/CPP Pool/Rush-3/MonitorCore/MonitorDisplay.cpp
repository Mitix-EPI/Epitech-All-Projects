/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** MonitorDisplay
*/

#include "MonitorDisplay.hpp"

MonitorDisplay::MonitorDisplay() : _cpu(*(new Cpu())), _mem(*(new Memory())), _user(*(new User())), _time(*(new Time())), _network(*(new Network())), _task(*(new Tasks()))
{
}

MonitorDisplay::~MonitorDisplay()
{
}
