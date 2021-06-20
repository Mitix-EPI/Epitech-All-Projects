/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

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

typedef struct network_data_s {
    std::string name;
    float up;
    float down;
} network_data_t;
typedef struct network_data_unsigned_s {
    std::string name;
    unsigned int up;
    unsigned int down;
} network_data_unsigned_t;

class Network: public MonitorModule {
    public:
        Network(std::string const &name = "Network", std::string const &type = "Network");
        ~Network();
        void updateData();
        int getSize() const{return this->_data.size();};
        std::vector<network_data_t> getData() const {return _data;};

    protected:
    private:
        std::vector<network_data_t> _data;
        std::vector<network_data_unsigned_t> _currentData;
        std::vector<network_data_unsigned_t> _previousData;
};

#endif /* !NETWORK_HPP_ */
