/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** MonitorDisplay
*/

#ifndef MONITORDISPLAY_HPP_
#define MONITORDISPLAY_HPP_

#include "IMonitorDisplay.hpp"
#include "../Modules/Cpu.hpp"
#include "../Modules/Memory.hpp"
#include "../Modules/Time.hpp"
#include "../Modules/User.hpp"
#include "../Modules/Network.hpp"
#include "../Modules/Tasks.hpp"

class MonitorDisplay : public IMonitorDisplay {
    public:
        MonitorDisplay();
        virtual ~MonitorDisplay();
        virtual void init(void) = 0;
        virtual void run(void) = 0;
        virtual void update(void) = 0;
        virtual void display(void) = 0;
        virtual void destroy(void) = 0;
    /* GET */
        Cpu getCpu(void) const { return this->_cpu; }
        Memory getMemory(void) const { return this->_mem; }
        User getUser(void) const { return this->_user; }
        Time getTime(void) const { return this->_time; }
        Network getNetwork(void) const { return this->_network; }

    protected:
        Cpu _cpu;
        Memory _mem;
        User _user;
        Time _time;
        Network _network;
        Tasks _task;
    private:
};

#endif /* !MONITORDISPLAY_HPP_ */
