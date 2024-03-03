/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "../AbstractComponent.hpp"

namespace nts::Components {
    class P4512Component : public AbstractComponent {
        public:
            // ------ PINS ------
            static inline const std::size_t X0 = 1;
            static inline const std::size_t X1 = 2;
            static inline const std::size_t X2 = 3;
            static inline const std::size_t X3 = 4;
            static inline const std::size_t X4 = 5;
            static inline const std::size_t X5 = 6;
            static inline const std::size_t X6 = 7;
            static inline const std::size_t VSS = 8;
            static inline const std::size_t X7 = 9;
            static inline const std::size_t INHIBIT = 10;
            static inline const std::size_t A = 11;
            static inline const std::size_t B = 12;
            static inline const std::size_t C = 13;
            static inline const std::size_t Z = 14;
            static inline const std::size_t OE = 15;
            static inline const std::size_t VDD = 16;
            // ------ PINS ------
            P4512Component();
            nts::Tristate internalCompute(std::size_t pin) override;
            [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}