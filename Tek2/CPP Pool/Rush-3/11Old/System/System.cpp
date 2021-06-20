/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** hostName
*/

#include "System.hpp"

System::System() {
    std::ifstream fHost("/proc/sys/kernel/hostname");
    std::ifstream fVersion("/proc/version");
    std::string str = "";

    this->_usr = std::getenv("USER");
    while (getline(fHost, str))
        this->_hostName.push_back(str);
    getline(fVersion, str);
    this->_osVersion = str.substr(0, str.find(" ("));
    sysinfo(&this->_sys);
}

System::~System() {}

void System::updateSys() {
    sysinfo(&this->_sys);
}

void System::updateData() {
    sysinfo(&this->_sys);
}

std::string System::getUptime() const {
    std::stringstream stream;
    std::string res = "";

    stream << this->getUptimeDay() << ":" << this->getUptimeHour() << ":" << this->getUptimeMinute();
    stream >> res;
    return (res);
}

std::string System::getActualDate() const {
    std::time_t now = time(0);
    std::tm *ltm = localtime(&now);
    std::stringstream stream;
    std::string date;
    stream << ltm->tm_mday << ":" << (1 + ltm->tm_mon) << ":" << (1900 + ltm->tm_year);
    stream >> date;
    return (date);
}


std::string System::getActualTime() const {
    std::time_t now = time(0);
    std::tm *ltm = localtime(&now);
    std::stringstream stream;
    std::string date;
    stream << ltm->tm_hour << ":" << ltm->tm_min;
    stream >> date;
    return (date);
}

int main(void) {
    System r;
    struct sysinfo _sys;

    std::cout << "UserName => " << r.getUserName() << std::endl;
    for (const auto &it : r.getHostName())
        std::cout << it << std::endl;
    std::cout << "OsVersion => " << r.getOsVersion() << std::endl;
    std::cout << "total RAM => " << r.getTotaRamMB() * 0.000977 << std::endl;
    std::cout << "Free RAM => " << r.getFreeRamMB() * 0.000977 << std::endl;
    std::cout << "Used RAM => " << r.getTotaRamMB() -r.getFreeRamMB() * 0.000977 << std::endl;
    std::cout << "total Swap => " << r.getTotalSwapMB() << std::endl;
    std::cout << "Free Swap => " << r.getFreeSwapMB() << std::endl;
    std::cout << "Uptime => " << r.getUptime() << std::endl;
    std::cout << "Proc => " << r.getNbProc() << std::endl;
    std::cout << "Date => " << r.getActualDate() << std::endl;
    std::cout << "Time => " << r.getActualTime() << std::endl;

    std::cout << "Ram Shard => " << r.getFreeSharedMB() + r.getBufferMB() + r.getFreeRamMB() << std::endl;
    std::cout << "Calc => " << (r.getTotaRamMB() - r.getFreeRamMB()) * 0.000977 << std::endl;
    return (0);
}