#pragma once

#include "IComponent.hpp"
#include <unordered_map>
#include <functional>
#include <utility> // std::pair
#include "Components.hpp"

class ComponentFactory {

    public:
        ComponentFactory();
        ~ComponentFactory();

        std::unique_ptr<nts::IComponent> gemme_component(std::string);

    private:
        std::unordered_map<std::string, std::function<nts::IComponent *()>> map;
};

std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
