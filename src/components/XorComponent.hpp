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
    class XorComponent: public AbstractComponent {
    public:
        XorComponent();
        ~XorComponent() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] XorComponent *clone() const override;
    };
}
