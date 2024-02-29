/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ComponentFactory.hpp"

namespace nts {
    ComponentFactory::ComponentFactory() {
        _components = std::unordered_map<std::string, IComponent *>();
    }

    ComponentFactory::~ComponentFactory() {
        for (auto &component : _components) {
            delete component.second;
        }
    }

    void ComponentFactory::registerComponent(const std::string &name, IComponent *component)
    {
        _components[name] = component;
    }

    std::unique_ptr<IComponent> ComponentFactory::operator<<(const std::string &name)
    {
        return _components[name]->clone();
    }

    std::unique_ptr<IComponent> ComponentFactory::createComponent(const std::string &name)
    {
        return _components[name]->clone();
    }

    void ComponentFactory::unregisterComponent(const std::string &name)
    {
        _components.erase(name);
    }

    bool ComponentFactory::isRegistered(const std::string &name)
    {
        return _components.find(name) != _components.end();
    }
}