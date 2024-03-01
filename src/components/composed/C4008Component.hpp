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
    class C4008Component: public ComposedComponent {
    public:
        // ------ PINS ------
        static inline const std::size_t A4 = 1;
        static inline const std::size_t B3 = 2;
        static inline const std::size_t A3 = 3;
        static inline const std::size_t B2 = 4;
        static inline const std::size_t A2 = 5;
        static inline const std::size_t B1 = 6;
        static inline const std::size_t A1 = 7;
        static inline const std::size_t VSS = 8;
        static inline const std::size_t CIN = 9;
        static inline const std::size_t Y1 = 10;
        static inline const std::size_t Y2 = 11;
        static inline const std::size_t Y3 = 12;
        static inline const std::size_t Y4 = 13;
        static inline const std::size_t COUT = 14;
        static inline const std::size_t B4 = 15;
        static inline const std::size_t VDD = 16;
        // ------ PINS ------
        C4008Component();
        ~C4008Component() override = default;
        Tristate internalCompute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
