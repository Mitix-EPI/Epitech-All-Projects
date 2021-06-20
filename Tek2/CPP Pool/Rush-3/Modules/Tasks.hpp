/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Tasks
*/

#ifndef TASKS_HPP_
#define TASKS_HPP_

#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include "../MonitorCore/MonitorModule.hpp"

class Tasks: public MonitorModule {
    public:
        Tasks(std::string const &name = "Tasks", std::string const &type = "Tasks");
        ~Tasks();
        void updateData();
        int getNumProc(void) const{return _numProc;};
        void setNumProc(void);
        std::vector<float> getAverage(void);

    protected:
    private:
        int _numProc;
};

#endif /* !TASKS_HPP_ */
