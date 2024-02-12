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
    private:
        Tristate _value;
    public:
        InputComponent();
        ~InputComponent() override = default;
        Tristate compute(std::size_t pin) override;
        void setValue(Tristate value);
        [[nodiscard]] InputComponent *clone() const override;
    };
}