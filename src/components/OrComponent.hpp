/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "AbstractComponent.hpp"

namespace nts::Components {
    class OrComponent: public AbstractComponent {
    public:
        OrComponent();
        ~OrComponent() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] OrComponent *clone() const override;
    };
}