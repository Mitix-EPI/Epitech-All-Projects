/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <sstream>
#include <ctime>
#include <iostream>
#include <string>
#include <sys/sysinfo.h>
#include <chrono>
#include "../MonitorCore/MonitorModule.hpp"

class Time: public MonitorModule {
    public:
        Time(std::string const &name = "Time", std::string const &type = "Time");
        ~Time();
        void updateData(void) override;
    public:
        unsigned int getUptimeDay() const;
        unsigned int getUptimeHour() const;
        unsigned int getUptimeMinute() const;
        unsigned int getUptimeSecond() const;
    public:
        std::string getUptime() const;
        std::string getActualDate() const;
        std::string getActualTime() const;
    protected:
        struct sysinfo _sys;
};

#endif /* !TIME_HPP_ */
