/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Time
*/

#include "Time.hpp"

Time::Time(std::string const &name, std::string const &type) :  MonitorModule(name, type) {
    sysinfo(&this->_sys);
}

Time::~Time()
{
}

void Time::updateData(void) {
    sysinfo(&this->_sys);
}

std::string Time::getUptime() const {
    std::stringstream stream;
    std::string res = "";
    std::string space = " ";

    res = std::to_string(this->getUptimeDay()) + " day | " + std::to_string(this->getUptimeHour()) + ":" + std::to_string(this->getUptimeMinute()) + ":" + std::to_string(this->getUptimeSecond());
    return (res);
}

std::string Time::getActualDate() const {
    std::time_t now = time(0);
    std::tm *ltm = localtime(&now);
    std::stringstream stream;
    std::string date;
    stream << ltm->tm_mday << ":" << (1 + ltm->tm_mon) << ":" << (1900 + ltm->tm_year);
    stream >> date;
    return (date);
}


std::string Time::getActualTime() const {
    std::time_t now = time(0);
    std::tm *ltm = localtime(&now);
    std::stringstream stream;
    std::string date;
    stream << ltm->tm_hour << ":" << ltm->tm_min;
    stream >> date;
    return (date);
}

unsigned int Time::getUptimeMinute() const {
    int days = 1;
    int hours = 1;
    int mins = 1;

    days = this->_sys.uptime / 86400;
    hours = (this->_sys.uptime / 3600) - (days * 24);
    mins = (this->_sys.uptime / 60) - (days * 1440) - (hours * 60);
    return (mins);
}

unsigned int Time::getUptimeDay() const {
    int days = 1;

    days = this->_sys.uptime / 86400;
    return (days);
}

unsigned int Time::getUptimeHour() const {
    int days = 1;
    int hours = 1;

    days = this->_sys.uptime / 86400;
    hours = (this->_sys.uptime / 3600) - (days * 24);
    return (hours);
}

unsigned int Time::getUptimeSecond() const {
    return (this->_sys.uptime % 60);
}

// int main(void) {
//     Time r;

//     std::cout << "Uptime => " << r.getUptime() << std::endl;
//     std::cout << "Date => " << r.getActualDate() << std::endl;
//     std::cout << "Time => " << r.getActualTime() << std::endl;
//     return (0);
// }