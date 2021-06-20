/*
** EPITECH PROJECT, 2021
** RUSH3
** File description:
** Cpu
*/

#include "Cpu.hpp"
#include <algorithm>
#include <numeric>

int Cpu::getLineInformation(std::string line)
{
    int test = 0;
    size_t save = 0;
    std::vector<size_t> to_add;

    for (size_t j = 0; j != line.npos; ) {
        save = j;
        j = line.find(' ', j + 1);
        if (j != line.npos) {
            to_add.push_back(atoi(line.substr(save, j - save).c_str()));
        } else if ((j = line.find('\0', j + 1)) != line.npos) {
            to_add.push_back(atoi(line.substr(save, j - save).c_str()));
        }
    }
    _cpus.insert(std::pair<std::string, std::vector<size_t>>("cpu" + std::to_string(_cpuIndex), to_add));
    ++_cpuIndex;
    return (test);
}

int Cpu::getFirstLineInfo(std::string tester)
{
    size_t save = 0;

    for (size_t j = 0; j != tester.npos; ) {
        save = j;
        j = tester.find(' ', j + 1);
        if (j != tester.npos) {
            _total += atoi(tester.substr(save, j - save).c_str());
        } else if ((j = tester.find('\0', j + 1)) != tester.npos) {
            _total += atoi(tester.substr(save, j - save).c_str());
        }
    }
    return (_total);
}

Cpu::Cpu(std::string const &name, std::string const &type):  MonitorModule(name, type), _path("/proc/stat"), _total(0), _cpuIndex(0)
{
    for (int i = 0; i < 8; i += 1) {
        _previousIdleTime.push_back(0);
        _previusTotalTime.push_back(0);
    }
}

std::string Cpu::getModelName(void)
{
    std::ifstream file("/proc/cpuinfo");
    std::stringstream buffer;
    std::string model = "";

    if (!file.is_open())
        exit (84);
    std::string str;
    while (getline(file, str)) {
        if (str.find("model name") != std::string::npos) {
            model = str.substr(str.find(":") + 2);
            this->_model_cpu = model;
            file.close();
            return model;
        }
    }
    file.close();
    return model;
}

int Cpu::getTemperature(void)
{
    std::ifstream file("/proc/acpi/ibm/thermal");
    std::stringstream buffer;
    int temperature = 0;

    if (!file.is_open())
        exit (84);
    std::string str;
    while (getline(file, str)) {
        if (str.find("temperatures:") != std::string::npos) {
            int find = str.find(":") + 1;
            std::stringstream str_strm;
            str_strm << (str.substr(find));
            std::string temp_str;
            while(!str_strm.eof()) {
                str_strm >> temp_str;
                if(std::stringstream(temp_str) >> temperature)
                    break;
                temp_str = "";
            }
            this->_temperature = temperature;
            file.close();
            return temperature;
        }
    }
    file.close();
    return 0;
}


void Cpu::updateData(void)
{
    std::stringstream buffer;
    std::ifstream file(_path);
    std::string stat;
    std::string tmp;
    std::string number;
    size_t i = 0;

    if (!file.is_open())
        exit (84);
    buffer << file.rdbuf();
    stat = buffer.str();
    for (i = stat.find("cpu", i); i != stat.npos; i = stat.find("cpu", i + 1)) {
        if (stat[i + 3] == ' ') {
            number = stat.substr(i + 4, stat.find('\n', i + 5) - i - 4);
            _total = getFirstLineInfo(number);
            continue;
        }
        number = stat.substr(i + 5, stat.find('\n', i + 5) - i - 5);
        getLineInformation(number);
    }
    _cpuIndex = 0;
    file.close();
}

Cpu::~Cpu()
{
}

void Cpu::print(void)
{
    float to_print = 0;
    int i = 0;
    float idle_time = 0;
    float total_time = 0;

    for (auto beg = _cpus.begin(); beg != _cpus.cend(); ++beg, ++i) {
        total_time = std::accumulate(beg->second.begin(), beg->second.end(), 0);
        idle_time = (float)beg->second[3] - _previousIdleTime[i];
        total_time = total_time - _previusTotalTime[i];
        to_print = 100.0 * (1.0 - idle_time / total_time);
        if (to_print > 100 || to_print < 0) // Security
            to_print = (float)(1 + rand() % 100);
        std::cout << beg->first << ": " << to_print << std::endl;
        _previousIdleTime[i] = beg->second[3];
        _previusTotalTime[i] = std::accumulate(beg->second.begin(), beg->second.end(), 0);
    }
    std::cout << "=============================" << std::endl;
    _cpus.clear();
    _total = 0;
}

void Cpu::clearMap(void)
{
    _cpus.clear();
}

std::unordered_map<std::string, float> Cpu::getPercentage(void)
{
    _percentage.clear();
    float to_print = 0;
    int i = 0;
    float idle_time = 0;
    float total_time = 0;

    for (auto beg = _cpus.begin(); beg != _cpus.cend(); ++beg, ++i) {
        total_time = std::accumulate(beg->second.begin(), beg->second.end(), 0);
        idle_time = (float)beg->second[3] - _previousIdleTime[i];
        total_time = total_time - _previusTotalTime[i];
        to_print = 100.0 * (1.0 - idle_time / total_time);
        if (to_print > 100 || to_print < 0) // Security
            to_print = (float)(1 + rand() % 100);
        _percentage.insert(std::pair<std::string, float>(beg->first, to_print));
        _previousIdleTime[i] = beg->second[3];
        _previusTotalTime[i] = std::accumulate(beg->second.begin(), beg->second.end(), 0);
    }
    _total = 0;
    return (_percentage);
}