/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** User
*/

#ifndef NAME_HPP_
#define NAME_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include "../MonitorCore/MonitorModule.hpp"

class User: public MonitorModule {
    public:
        User(std::string const &name = "User", std::string const &type = "User");
        ~User();
        void updateData(void);
    public:
        const std::string &getUserName(void) const { return (this->_usr); }
        const std::vector<std::string> getHostName(void) const { return (this->_hostUser); }
        const std::string &getOsVersion(void) const { return (this->_osVersion); }
    protected:
        std::string _usr;
        std::vector<std::string> _hostUser;
        std::string _osVersion;
};

#endif /* !NAME_HPP_ */
