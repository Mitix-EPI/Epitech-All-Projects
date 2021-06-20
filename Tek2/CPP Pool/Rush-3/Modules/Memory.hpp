/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include "../MonitorCore/MonitorModule.hpp"

class Memory: public MonitorModule {
    public:
        Memory(std::string const &name = "Memory", std::string const &type = "Memory");
        ~Memory();
    public:
        unsigned short getNbProc() const { return (this->_sys.procs); }
        float getTotalRamMB() const;
        float getCurrentRamMB() const;
        float getTotalSwapMB() const;
        float getFreeSwapMB() const;
        void updateData(){};
    protected:
        struct sysinfo _sys;
};

#endif /* !MEMORY_HPP_ */
