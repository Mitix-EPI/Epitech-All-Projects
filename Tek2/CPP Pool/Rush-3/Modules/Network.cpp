/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Network
*/

#include "Network.hpp"

Network::Network(std::string const &name, std::string const &type):  MonitorModule(name, type)
{
    std::ifstream stream;
    stream.open("/proc/net/dev");
    std::string str;
    while (getline(stream, str))
        if (str.find(":") !=  std::string::npos && str.substr(0, str.find(":")) != "lo") {
            int find = str.find(":") + 1;
            std::string name = str.substr(0, find - 1);
            name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
            std::stringstream str_strm;
            str_strm << (str.substr(find));
            std::string temp_str;
            unsigned int temp_int;
            int count = 0;
            network_data_t newData;
            newData.name = name;
            network_data_unsigned_t newCurrentData;
            newData.name = name;
            while(!str_strm.eof()) {
                str_strm >> temp_str;
                if(std::stringstream(temp_str) >> temp_int) {
                    if (count == 0) {
                        newData.up = 0;
                        newCurrentData.down = temp_int;
                    } else if (count == 8) {
                        newData.down = 0;
                        newCurrentData.up = temp_int;
                    }
                    count ++;
                }
                temp_str = "";
            }
            this->_currentData.push_back(newCurrentData);
            this->_data.push_back(newData);
        }
}

Network::~Network()
{
}

void Network::updateData()
{
    std::ifstream stream;
    stream.open("/proc/net/dev");
    std::string str;
    this->_previousData.clear();
    for (network_data_unsigned_t n : this->_currentData)
        this->_previousData.push_back(n);
    this->_data.clear();
    this->_currentData.clear();
    while (getline(stream, str))
        if (str.find(":") != std::string::npos && str.substr(0, str.find(":")) != "lo") {
            int find = str.find(":") + 1;
            std::string name = str.substr(0, find - 1);
            name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
            std::stringstream str_strm;
            str_strm << (str.substr(find));
            std::string temp_str;
            unsigned int temp_int;
            int count = 0;
            network_data_unsigned_t newData;
            newData.name = name;
            while(!str_strm.eof()) {
                str_strm >> temp_str;
                if(std::stringstream(temp_str) >> temp_int) {
                    if (count == 0)
                        newData.down = temp_int;
                    else if (count == 8)
                        newData.up = temp_int;
                    count ++;
                }
                temp_str = "";
            }
            this->_currentData.push_back(newData);
        }
    std::cout << std::endl << std::endl;
    for (std::size_t i = 0; i < this->_currentData.size(); i++) {
        network_data_t newData;
        newData.name = this->_currentData[i].name;
        newData.up = (this->_currentData[i].up - this->_previousData[i].up) * 0.000977;
        newData.down = (this->_currentData[i].down - this->_previousData[i].down) * 0.000977;
        this->_data.push_back(newData);
    }
    std::cout << std::endl << std::endl;
}

// int main()
// {
//     Network net;
//     int size = net.getSize();
//     std::vector<network_data_t> data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     sleep(1);
//     net.updateData();
//     data = net.getData();
//     for (network_data_t n : data) {
//         std::cout << "name : " << n.name << ", up : " << n.up << ", down : " << n.down << std::endl;
//     }
//     return (0);
// }