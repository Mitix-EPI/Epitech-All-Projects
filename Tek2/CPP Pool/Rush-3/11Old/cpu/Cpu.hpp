/*
** EPITECH PROJECT, 2021
** RUSH3
** File description:
** Cpu
*/

#ifndef CPU_HPP_
#define CPU_HPP_
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

class Cpu {
    public:
        Cpu();
        ~Cpu();

        void update();
        void print();
        int getLineInformation(std::string);
        int getFirstLineInfo(std::string tester);
        std::unordered_map<std::string, std::vector<size_t>> getCPUs(void) const { return this->_cpus; }
        std::unordered_map<std::string, float> getPercentage(void);
        void clearMap(void);

    protected:
        std::string _path;
        std::unordered_map<std::string, std::vector<size_t>> _cpus;
        std::unordered_map<std::string, float> _percentage;
        int _total;
        int _cpuIndex;
        std::vector <size_t> _previousIdleTime;
        std::vector <size_t> _previusTotalTime;
};

#endif /* !CPU_HPP_ */
