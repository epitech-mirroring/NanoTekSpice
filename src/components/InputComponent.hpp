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
    public:
        InputComponent();
        ~InputComponent() override = default;
        Tristate compute(std::size_t pin) override;
        void setValue(Tristate value);
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
