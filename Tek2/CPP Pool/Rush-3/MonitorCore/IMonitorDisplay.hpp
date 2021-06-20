/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-clement.bolin
** File description:
** IMonitorDisplay
*/

//hello world
//<3

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <string>
#include <unordered_map>

class IMonitorDisplay {
    public:
        virtual void init(void) = 0;
        virtual void run(void) = 0;
        virtual void update(void) = 0;
        virtual void display(void) = 0;
        virtual void destroy(void) = 0;
};

#endif /* !IMONITORDISPLAY_HPP_ */
