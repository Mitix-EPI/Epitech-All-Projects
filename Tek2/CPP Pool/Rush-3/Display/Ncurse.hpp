/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Ncurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_

#include "../MonitorCore/MonitorDisplay.hpp"
#include <ncurses.h>
#include <math.h>
#include <assert.h>

class Ncurse: public MonitorDisplay {
    public:
        Ncurse();
        ~Ncurse();

        void run(void);
        void init(void);
        void update(void);
        void display(void);
        void destroy(void);
        void displayCore(void);
        void displayProcess(void);
        void displayUserInfo(void);
        void displayDataTransfer(void);

    protected:
    private:
};

#endif /* !NCURSE_HPP_ */
