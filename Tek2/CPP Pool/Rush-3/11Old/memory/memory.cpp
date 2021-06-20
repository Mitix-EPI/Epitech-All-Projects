#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

int main()
{
    std::ifstream stream;
    stream.open("/proc/meminfo");
    std::string str;
    size_t val = 0;
    std::string name;
    std::unordered_map<std::string, size_t> memory_data;
    memory_data["MemTotal"] = 15;
    memory_data["SwapTotal"] = 15;
    memory_data["SwapFree"] = 15;
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
    float usedRam = ((memory_data["MemTotal"] - memory_data["MemFree"]) - (memory_data["Buffers"] + (memory_data["Cached"] + memory_data["SReclaimable"] - memory_data["Shmem"]))) * 0.000000954;
    float totalRam = memory_data["MemTotal"] * 0.000000954;
    float usedSwap = (memory_data["SwapTotal"] - memory_data["SwapFree"]) * 0.000000954;
    float totalSwap = memory_data["SwapTotal"] * 0.000000954;
    std::cout << "Used : " << usedRam << std::endl;
    std::cout << "Total : " << totalRam << std::endl;
    std::cout << "Swap Used : " << usedSwap << std::endl;
    std::cout << "Total : " << totalSwap << std::endl;
    stream.close();
    return (0);
}