/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** MonitorModule
*/

#ifndef MONITORMODULE_HPP_
#define MONITORMODULE_HPP_

#include "IMonitorModule.hpp"
#include <unordered_map>

class MonitorModule: public IMonitorModule {
    public:
        MonitorModule(std::string const &name = "", std::string const &type = "");
        ~MonitorModule();
    /* GET */
        std::string getName(void) const override;
        std::string getType(void) const override;
        bool isShown(void) const{return this->_isShown;};
    /* SET */
        void setIsShown(void) {this->_isShown = !this->_isShown;};
        void setType(std::string const &str) override;
        virtual void updateData(void) = 0;

    protected:
        std::string _name;
        std::string _type;
        bool _isShown;


    private:
};

#endif /* !MonitorModule_HPP_ */
