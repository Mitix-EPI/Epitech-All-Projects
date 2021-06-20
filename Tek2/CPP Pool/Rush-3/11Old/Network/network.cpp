/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** network
*/

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

using namespace std;

int main()
{
    ifstream stream;
    stream.open("/proc/net/dev");
    string str;
    while (getline(stream, str))
        if (str.find(":") != -1) {
            int find = str.find(":") + 1;
            string name = str.substr(0, find - 1);
            name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
            stringstream str_strm;
            str_strm << (str.substr(find));
            string temp_str;
            int temp_int;
            int res = 0;
            while(!str_strm.eof()) {
                str_strm >> temp_str;
                if(stringstream(temp_str) >> temp_int)
                    res += temp_int;
                temp_str = "";
            }
            cout << "name : " << name << "   size : " << res << endl << endl;
        }
}