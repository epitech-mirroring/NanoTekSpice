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
    class OutputComponent: public AbstractComponent {
    private:
        Tristate _value;
    public:
        OutputComponent();
        ~OutputComponent() override = default;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] OutputComponent *clone() const override;
    };
}
