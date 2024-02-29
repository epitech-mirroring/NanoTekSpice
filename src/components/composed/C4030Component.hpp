/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "../ComposedComponent.hpp"

namespace nts::Components {
    class C4030Component: public ComposedComponent {
    public:
        // ------ PINS ------
        static inline const std::size_t A1 = 1;
        static inline const std::size_t B1 = 2;
        static inline const std::size_t Y1 = 3;
        static inline const std::size_t Y2 = 4;
        static inline const std::size_t B2 = 5;
        static inline const std::size_t A2 = 6;
        static inline const std::size_t VSS = 7;
        static inline const std::size_t A3 = 8;
        static inline const std::size_t B3 = 9;
        static inline const std::size_t Y3 = 10;
        static inline const std::size_t Y4 = 11;
        static inline const std::size_t B4 = 12;
        static inline const std::size_t A4 = 13;
        static inline const std::size_t VDD = 14;
        // ------ PINS ------
        C4030Component();
        ~C4030Component() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
