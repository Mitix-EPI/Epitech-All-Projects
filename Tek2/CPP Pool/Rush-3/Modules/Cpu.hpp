/*
** EPITECH PROJECT, 2021
** RUSH3
** File description:
** Cpu
*/

#ifndef CPU_HPP_
#define CPU_HPP_
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
#include <cstdlib>
#include "../MonitorCore/MonitorModule.hpp"

class Cpu: public MonitorModule {
    public:
        Cpu(std::string const &name = "CPU", std::string const &type = "CPU");
        ~Cpu();

        void updateData(void);
        void print();
        int getLineInformation(std::string);
        int getFirstLineInfo(std::string tester);
        size_t getNumberCores(void) const { return this->_cpus.size(); };
        std::string getModelName(void);
        std::unordered_map<std::string, std::vector<size_t>> getCPUs(void) const { return this->_cpus; }
        std::unordered_map<std::string, float> getPercentage(void);
        int getTemperature(void);
        void clearMap(void);

    protected:
        std::string _path;
        std::unordered_map<std::string, std::vector<size_t>> _cpus;
        std::unordered_map<std::string, float> _percentage;
        int _total;
        int _cpuIndex;
        std::vector <size_t> _previousIdleTime;
        std::vector <size_t> _previusTotalTime;
        std::string _model_cpu;
        int _temperature;
};

#endif /* !CPU_HPP_ */
