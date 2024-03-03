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
    class P4514Component : public AbstractComponent {
    protected:
        Tristate a;
        Tristate b;
        Tristate c;
        Tristate d;
    public:
        // ------ PINS ------
        static inline const std::size_t STORE = 1;
        static inline const std::size_t IN_A = 2;
        static inline const std::size_t IN_B = 3;
        static inline const std::size_t S7 = 4;
        static inline const std::size_t S6 = 5;
        static inline const std::size_t S5 = 6;
        static inline const std::size_t S4 = 7;
        static inline const std::size_t S3 = 8;
        static inline const std::size_t S1 = 9;
        static inline const std::size_t S2 = 10;
        static inline const std::size_t S0 = 11;
        static inline const std::size_t VSS = 12;
        static inline const std::size_t S13 = 13;
        static inline const std::size_t S12 = 14;
        static inline const std::size_t S15 = 15;
        static inline const std::size_t S14 = 16;
        static inline const std::size_t S9 = 17;
        static inline const std::size_t S8 = 18;
        static inline const std::size_t S11 = 19;
        static inline const std::size_t S10 = 20;
        static inline const std::size_t IN_C = 21;
        static inline const std::size_t IN_D = 22;
        static inline const std::size_t INHIBIT = 23;
        static inline const std::size_t VDD = 24;
        // ------ PINS ------
        P4514Component();
        ~P4514Component() override = default;
        Tristate internalCompute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
