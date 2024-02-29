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
    class C7482Component: public ComposedComponent {
    public:
        // ------ PINS ------
        static inline const std::size_t Y1 = 1;
        static inline const std::size_t A1 = 2;
        static inline const std::size_t B1 = 3;
        static inline const std::size_t VSS = 4;
        static inline const std::size_t CIN = 5;
        static inline const std::size_t NC_1 = 6;
        static inline const std::size_t NC_2 = 7;
        static inline const std::size_t NC_3 = 8;
        static inline const std::size_t NC_4 = 9;
        static inline const std::size_t COUT = 10;
        static inline const std::size_t VDD = 11;
        static inline const std::size_t Y2 = 12;
        static inline const std::size_t B2 = 13;
        static inline const std::size_t A2 = 14;
        // ------ PINS ------
        C7482Component();
        ~C7482Component() override = default;
        Tristate compute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}