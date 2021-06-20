
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
    try : _api(input, output)
{
}
catch(std::exception &e)
{
    std::string tmp = static_cast<std::string>(e.what());
    throw CommunicationError("Error: " + tmp);
}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    }
    catch (std::logic_error &logic)
    {
        std::string tmp = std::string(logic.what());
        throw CommunicationError("LogicError: " + tmp);
    }
    catch (std::runtime_error &runtime)
    {
        std::string tmp = std::string(runtime.what());
        throw CommunicationError("RuntimeError: " + tmp);
    }
    catch (std::exception &e)
    {
        std::string tmp = std::string(e.what());
        throw CommunicationError("Error: " + tmp);
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        message = "INVALID MESSAGE";
    }
}
