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
    class TrueComponent : public AbstractComponent {
    public:
        // ------ PINS ------
        static inline const std::size_t OUT = 1;
        // ------ PINS ------
        TrueComponent();
        ~TrueComponent() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
