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
    class AndComponent: public AbstractComponent {
    public:
        // ------ PINS ------
        static inline const std::size_t IN_1 = 1;
        static inline const std::size_t IN_2 = 2;
        static inline const std::size_t OUT = 3;
        // ------ PINS ------
        AndComponent();
        ~AndComponent() override = default;
        Tristate internalCompute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
