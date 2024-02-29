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
    class C4069Component: public ComposedComponent {
    public:
        // ------ PINS ------
        static inline const std::size_t IN_1 = 1;
        static inline const std::size_t OUT_1 = 2;
        static inline const std::size_t IN_2 = 3;
        static inline const std::size_t OUT_2 = 4;
        static inline const std::size_t IN_3 = 5;
        static inline const std::size_t OUT_3 = 6;
        static inline const std::size_t VSS = 7;
        static inline const std::size_t IN_4 = 9;
        static inline const std::size_t OUT_4 = 8;
        static inline const std::size_t IN_5 = 11;
        static inline const std::size_t OUT_5 = 10;
        static inline const std::size_t IN_6 = 13;
        static inline const std::size_t OUT_6 = 12;
        static inline const std::size_t VDD = 14;
        // ------ PINS ------
        C4069Component();
        ~C4069Component() override = default;
        Tristate internalCompute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
