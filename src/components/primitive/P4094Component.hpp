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
    class P4094Component : public AbstractComponent {
    protected:
        nts::Tristate _lastClockState;
        nts::Tristate values[8]{};
        nts::Tristate qs;
        nts::Tristate qs_prime;
    public:
        // ------ PINS ------
        static inline const std::size_t STROBE = 1;
        static inline const std::size_t DATA = 2;
        static inline const std::size_t CLOCK = 3;
        static inline const std::size_t Q1 = 4;
        static inline const std::size_t Q2 = 5;
        static inline const std::size_t Q3 = 6;
        static inline const std::size_t Q4 = 7;
        static inline const std::size_t VSS = 8;
        static inline const std::size_t QS = 9;
        static inline const std::size_t QS_PRIME = 10;
        static inline const std::size_t Q8 = 11;
        static inline const std::size_t Q7 = 12;
        static inline const std::size_t Q6 = 13;
        static inline const std::size_t Q5 = 14;
        static inline const std::size_t OE = 15;
        static inline const std::size_t VDD = 16;
        // ------ PINS ------
        P4094Component();
        ~P4094Component() override = default;
        void beforeSimulation(size_t tick) override;
        void internalSimulate(std::size_t tick) override;
        Tristate internalCompute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
