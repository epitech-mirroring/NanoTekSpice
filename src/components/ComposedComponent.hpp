/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "AbstractComponent.hpp"
#include <unordered_map>

namespace nts::Components {
    class ComposedComponent: public AbstractComponent {
    protected:
        std::unordered_map<std::string, IComponent *> _internal;

        ComposedComponent(std::size_t nbPins, std::size_t nbInternals);
    public:
        ~ComposedComponent() override = default;
    };
}
