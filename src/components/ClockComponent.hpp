/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "InputComponent.hpp"

namespace nts::Components {
    class ClockComponent: public InputComponent {
    public:
        ClockComponent();
        ~ClockComponent() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] ClockComponent *clone() const override;
        void simulate(std::size_t tick) override;
    };
}
