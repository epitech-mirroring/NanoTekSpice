/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "../ComposedComponent.hpp"

namespace nts::Components {
    class CNandComponent: public ComposedComponent {
    public:
        CNandComponent();
        ~CNandComponent() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] CNandComponent *clone() const override;
    };
}
