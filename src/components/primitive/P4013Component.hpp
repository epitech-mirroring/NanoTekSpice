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
    class P4013Component : public AbstractComponent {
    protected:
        Tristate old_clk1 = UNDEFINED;
        Tristate old_clk2 = UNDEFINED;
        Tristate ff1_q = UNDEFINED;
        Tristate ff1_qb = UNDEFINED;
        Tristate ff2_q = UNDEFINED;
        Tristate ff2_qb = UNDEFINED;
    public:
        // ------ PINS ------
        static inline const std::size_t Q1 = 1;
        static inline const std::size_t Q1B = 2;
        static inline const std::size_t CLK1 = 3;
        static inline const std::size_t RS1 = 4;
        static inline const std::size_t D1 = 5;
        static inline const std::size_t S1 = 6;
        static inline const std::size_t VSS = 7;
        static inline const std::size_t S2 = 8;
        static inline const std::size_t D2 = 9;
        static inline const std::size_t RS2 = 10;
        static inline const std::size_t CLK2 = 11;
        static inline const std::size_t Q2B = 12;
        static inline const std::size_t Q2 = 13;
        static inline const std::size_t VDD = 14;
        // ------ PINS ------
        P4013Component();
        ~P4013Component() override = default;
        Tristate internalCompute(std::size_t pin) override;
        void beforeSimulation(std::size_t tick) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
