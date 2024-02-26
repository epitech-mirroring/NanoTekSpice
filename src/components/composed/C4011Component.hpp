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
    class C4011Component: public ComposedComponent {
    public:
        C4011Component();
        ~C4011Component() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] C4011Component *clone() const override;
    };
}