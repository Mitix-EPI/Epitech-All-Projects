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

int main()
{
    std::ifstream file("/proc/loadavg");
    std::stringstream buffer;
    std::string model = "";
    std::vector<float> res;
    float tmp = 0.0;

    if (!file.is_open())
        exit (84);
    std::string str;
    getline(file, str);
    buffer << str;
    buffer >> tmp; // TODO
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find(" "), str.size() - 1);
    buffer << str;
    buffer >> tmp; // TODO
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find(" "), str.size() - 1);
    buffer << str;
    buffer >> tmp; // TODO
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find(" "), str.size() - 1);
    buffer << str;
    buffer >> tmp; // TODO
    res.push_back(tmp);
    buffer.clear();
    str = str.substr(str.find("/") + 1, str.size() - 1);
    std::cout << "tmp : " << tmp << std::endl;
    buffer << str;
    buffer >> tmp; // TODO
    res.push_back(tmp);
    buffer.clear();
    file.close();
    return 0;
}