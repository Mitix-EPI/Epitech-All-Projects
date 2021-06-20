/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Memory
*/

#include "Memory.hpp"

Memory::Memory(std::string const &name, std::string const &type):  MonitorModule(name, type) 
{
    sysinfo(&this->_sys);
}

Memory::~Memory() {}

float Memory::getTotalRamMB() const
{
    std::ifstream stream;
    stream.open("/proc/meminfo");
    std::string str;
    size_t val = 0;
    std::string name;
    std::unordered_map<std::string, size_t> memory_data;
    memory_data["MemTotal"] = 15;
    while (getline(stream, str)) {
        std::stringstream(str) >> name >> val;
        name = name.substr(0, name.size() -1);
        if (memory_data[name] == 15) {
            memory_data[name] = val;
        }
    }
    stream.close();
    return memory_data["MemTotal"] * 0.000000954;
}

float Memory::getCurrentRamMB() const
{
    std::ifstream stream;
    stream.open("/proc/meminfo");
    std::string str;
    size_t val = 0;
    std::string name;
    std::unordered_map<std::string, size_t> memory_data;
    memory_data["MemTotal"] = 15;
    memory_data["MemFree"] = 15;
    memory_data["Buffers"] = 15;
    memory_data["Cached"] = 15;
    memory_data["SReclaimable"] = 15;
    memory_data["Shmem"] = 15;
    while (getline(stream, str)) {
        std::stringstream(str) >> name >> val;
        name = name.substr(0, name.size() -1);
        if (memory_data[name] == 15) {
            memory_data[name] = val;
        }
    }
    stream.close();
    return ((memory_data["MemTotal"] - memory_data["MemFree"]) - (memory_data["Buffers"] + (memory_data["Cached"] + memory_data["SReclaimable"] - memory_data["Shmem"]))) * 0.000000954;
}

float Memory::getTotalSwapMB() const
{
    std::ifstream stream;
    stream.open("/proc/meminfo");
    std::string str;
    size_t val = 0;
    std::string name;
    std::unordered_map<std::string, size_t> memory_data;
    memory_data["SwapTotal"] = 15;
    while (getline(stream, str)) {
        std::stringstream(str) >> name >> val;
        name = name.substr(0, name.size() -1);
        if (memory_data[name] == 15) {
            memory_data[name] = val;
        }
    }
    stream.close();
    return memory_data["SwapTotal"] * 0.000000954;
}

float Memory::getFreeSwapMB() const
{
    std::ifstream stream;
    stream.open("/proc/meminfo");
    std::string str;
    size_t val = 0;
    std::string name;
    std::unordered_map<std::string, size_t> memory_data;
    memory_data["SwapTotal"] = 15;
    memory_data["SwapFree"] = 15;
    while (getline(stream, str)) {
        std::stringstream(str) >> name >> val;
        name = name.substr(0, name.size() -1);
        if (memory_data[name] == 15) {
            memory_data[name] = val;
        }
    }
    stream.close();
    return (memory_data["SwapTotal"] - memory_data["SwapFree"]) * 0.000977;
}

// int main(void) {
//     Memory r;
//     std::cout << "total RAM => " << r.getTotalRamMB() << std::endl;
//     std::cout << "Free RAM => " << r.getCurrentRamMB() << std::endl;
//     std::cout << "total Swap => " << r.getTotalSwapMB() << std::endl;
//     std::cout << "Free Swap => " << r.getFreeSwapMB() << std::endl;
//     std::cout << "Proc => " << r.getNbProc() << std::endl;
//     return (0);
// }