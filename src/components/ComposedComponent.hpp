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
        std::unordered_map<std::string, AbstractComponent *> _internal;

        ComposedComponent(std::size_t nbPins, const std::string& name, std::size_t nbInternals);

        void setInternalLink(std::size_t pin, nts::IComponent &other,
                     std::size_t otherPin);
    public:
        ~ComposedComponent() override;
    };
}
