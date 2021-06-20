/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/sysinfo.h>


class System {
    public:
        System();
        ~System();
    public:
        void updateSys();
        void updateData();
    /* Get */
    public:
        const std::string &getUserName(void) const { return (this->_usr); }
        const std::vector<std::string> getHostName(void) const { return (this->_hostName); }
        const std::string &getOsVersion(void) const { return (this->_osVersion); }
        unsigned long getTotaRamMB() const { return (this->_sys.totalram / (1024 * 1024)); }
        unsigned long getFreeRamMB() const { return (this->_sys.freeram / (1024 * 1024)); }
        unsigned long getFreeSharedMB() const { return (this->_sys.sharedram / (1024 * 1024)); }
        unsigned long getBufferMB() const { return (this->_sys.bufferram / (1024 * 1024)); }
        unsigned long getTotalSwapMB() const { return (this->_sys.totalswap / (1024 * 1024)); }
        unsigned long getFreeSwapMB() const { return (this->_sys.freeswap / (1024 * 1024)); }
        unsigned long getUptimeDay() const { return (this->_sys.uptime / 8784); }
        unsigned long getUptimeHour() const { return (this->_sys.uptime / 3600); }
        unsigned long getUptimeMinute() const { return (this->_sys.uptime / 60); }
        unsigned long getCurrentUsedRam() const { return (this->getTotaRamMB() - (this->getFreeSharedMB() + this->getFreeRamMB())) * 0.000977; }
        unsigned short getNbProc() const { return (this->_sys.procs); }
    /* Get */
    public:
        std::string getUptime() const;
        std::string getActualDate() const;
        std::string getActualTime() const;
    protected:
        std::string _usr;
        std::vector<std::string> _hostName;
        std::string _osVersion;
        struct sysinfo _sys;
};

#endif /* !SYSTEM_HPP_ */
