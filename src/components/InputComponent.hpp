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
    class InputComponent: public AbstractComponent {
    protected:
        Tristate _value;
        Tristate _tempValue;
    public:
        // ------ PINS ------
        static inline const std::size_t OUT = 1;
        // ------ PINS ------
        InputComponent();
        ~InputComponent() override = default;
        Tristate internalCompute(std::size_t pin) override;
        void setValue(Tristate value);
        void internalSimulate(std::size_t tick) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
