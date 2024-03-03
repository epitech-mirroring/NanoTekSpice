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
    class P4040Component : public AbstractComponent {
    protected:
        std::size_t _value = 0;
        nts::Tristate _lastClk = nts::UNDEFINED;
    public:
        // ------ PINS ------
        static inline const std::size_t Q12 = 1;
        static inline const std::size_t Q6 = 2;
        static inline const std::size_t Q5 = 3;
        static inline const std::size_t Q7 = 4;
        static inline const std::size_t Q4 = 5;
        static inline const std::size_t Q3 = 6;
        static inline const std::size_t Q2 = 7;
        static inline const std::size_t VSS = 8;
        static inline const std::size_t Q1 = 9;
        static inline const std::size_t CLK = 10;
        static inline const std::size_t RS = 11;
        static inline const std::size_t Q9 = 12;
        static inline const std::size_t Q8 = 13;
        static inline const std::size_t Q10 = 14;
        static inline const std::size_t Q11 = 15;
        static inline const std::size_t VDD = 16;
        // ------ PINS ------
        P4040Component();
        ~P4040Component() override = default;
        Tristate internalCompute(std::size_t pin) override;
        void beforeSimulation(size_t tick) override;
        void internalSimulate(std::size_t tick) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
