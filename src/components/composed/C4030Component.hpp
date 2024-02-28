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
    class C4030Component: public ComposedComponent {
    public:
        C4030Component();
        ~C4030Component() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] C4030Component *clone() const override;
    };
}
