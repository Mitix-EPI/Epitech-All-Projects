/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** User
*/

#include "User.hpp"

User::User(std::string const &name, std::string const &type):  MonitorModule(name, type) {
    std::ifstream fHost("/proc/sys/kernel/hostname");
    std::ifstream fVersion("/proc/version");
    std::string str = "";

    this->_usr = std::getenv("USER");
    while (getline(fHost, str))
        this->_hostUser.push_back(str);
    getline(fVersion, str);
    this->_osVersion = str.substr(0, str.find(" ("));
}

User::~User() {}

void User::updateData(void)
{
    
}

// int main(void) {
//     User r;

//     std::cout << "UserUser => " << r.getUserUser() << std::endl;
//     for (const auto &it : r.getHostUser())
//         std::cout << it << std::endl;
//     std::cout << "OsVersion => " << r.getOsVersion() << std::endl;
//     return (0);
// }