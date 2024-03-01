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
    protected:
        Tristate _value;
        Tristate _tempValue;
        bool _hasChanged;
    public:
        // ------ PINS ------
        static inline const std::size_t OUT = 1;
        // ------ PINS ------
        ClockComponent();
        ~ClockComponent() override = default;
        Tristate compute(std::size_t pin) override;
        void setValue(Tristate value);
        void simulate(std::size_t tick) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
