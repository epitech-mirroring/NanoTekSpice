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
    class P4017Component : public AbstractComponent {
    protected:
        nts::Tristate _lastClk = nts::UNDEFINED;
        std::size_t _value = 0;
    public:
        // ------ PINS ------
        static inline const std::size_t Q5 = 1;
        static inline const std::size_t Q1 = 2;
        static inline const std::size_t Q0 = 3;
        static inline const std::size_t Q2 = 4;
        static inline const std::size_t Q6 = 5;
        static inline const std::size_t Q7 = 6;
        static inline const std::size_t Q3 = 7;
        static inline const std::size_t NC = 8;
        static inline const std::size_t Q8 = 9;
        static inline const std::size_t Q4 = 10;
        static inline const std::size_t Q9 = 11;
        static inline const std::size_t QB_5_9 = 12;
        static inline const std::size_t CPB_1 = 13;
        static inline const std::size_t CP_0 = 14;
        static inline const std::size_t MR = 15;
        // ------ PINS ------
        P4017Component();
        void beforeSimulation(size_t tick) override;
        void internalSimulate(std::size_t tick) override;
        nts::Tristate internalCompute(std::size_t pin) override;
        std::unique_ptr<nts::IComponent> clone() const override;
    };
}