/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

ComponentFactory::ComponentFactory()
{
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("input", []() { return new C_Input(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("output", []() { return new C_Output(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("true", []() { return new C_True(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("false", []() { return new C_False(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("clock", []() { return new C_Clock(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4081", []() { return new C_4081(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4071", []() { return new C_4071(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4001", []() { return new C_4001(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4069", []() { return new C_4069(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4030", []() { return new C_4030(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4013", []() { return new C_4013(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4008", []() { return new C_4008(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4011", []() { return new C_4011(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4040", []() { return new C_4040(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("logger", []() { return new C_Logger(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4017", []() { return new C_4017(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4514", []() { return new C_4514(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4094", []() { return new C_4094(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("2716", []() { exit(84); return new C_Input(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4512", []() { exit(84); return new C_Input(); }));
    map.insert(std::pair<std::string, std::function<nts::IComponent *()>>("4801", []() { exit(84); return new C_Input(); }));
}

std::unique_ptr<nts::IComponent> ComponentFactory::gemme_component(std::string component)
{
    return std::unique_ptr<nts::IComponent>(map[component]());
}

ComponentFactory::~ComponentFactory()
{
}

std::unique_ptr<nts::IComponent> createComponent(const std::string &type)
{
    ComponentFactory cf;

    return cf.gemme_component(type);
}
