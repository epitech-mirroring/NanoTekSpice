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
    class C4071Component: public ComposedComponent {
    public:
        C4071Component();
        ~C4071Component() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] C4071Component *clone() const override;
    };
}
