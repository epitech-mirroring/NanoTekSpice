/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <unordered_map>
#include <string>
#include "IComponent.hpp"

namespace nts {
    class ComponentFactory {
    private:
        std::unordered_map<std::string, IComponent *> _components;
    public:
        ComponentFactory();
        ~ComponentFactory();

        void registerComponent(const std::string &name, IComponent *component);
        [[nodiscard]] IComponent *operator<<(const std::string &name);
        [[nodiscard]] IComponent *createComponent(const std::string &name);
        void unregisterComponent(const std::string &name);
        bool isRegistered(const std::string &name);
    };
}
