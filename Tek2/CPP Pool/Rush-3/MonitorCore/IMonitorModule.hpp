/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-clement.bolin
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <string>
#include <unordered_map>

class IMonitorModule {
    public:
        virtual ~IMonitorModule() {}

    public:
    /* GET */
        virtual std::string getName(void) const = 0;
        virtual std::string getType(void) const = 0;
    /* SET */
        virtual void setType(std::string const &str) = 0;
    /* MEMBER FUNCTIONs */
        virtual void updateData(void) = 0;
};

#endif /* !IMONITORMODULE_HPP_ */
