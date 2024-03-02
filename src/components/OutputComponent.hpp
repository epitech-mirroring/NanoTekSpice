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
        // ------ PINS ------
        static inline const std::size_t IN = 1;
        // ------ PINS ------
        OutputComponent();
        ~OutputComponent() override = default;
        void internalSimulate(std::size_t tick) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
