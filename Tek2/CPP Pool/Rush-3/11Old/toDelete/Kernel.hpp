/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include "../MonitorModule.hpp"

class Time : public MonitorModule {
    public:
        Time(std::string const &name = "Kernel", std::string const &type = "OS");
        ~Time();
        void updateData(void);

    protected:
    private:
};

#endif /* !TIME_HPP_ */
