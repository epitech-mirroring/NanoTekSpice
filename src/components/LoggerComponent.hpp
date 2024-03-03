/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "AbstractComponent.hpp"
#include <fstream>

namespace nts::Components {
    class LoggerComponent : public AbstractComponent {
    protected:
        nts::Tristate _lastClock;
        std::ofstream _file;
    public:
        // ------ PINS ------
        static inline const std::size_t IN_0 = 1;
        static inline const std::size_t IN_1 = 2;
        static inline const std::size_t IN_2 = 3;
        static inline const std::size_t IN_3 = 4;
        static inline const std::size_t IN_4 = 5;
        static inline const std::size_t IN_5 = 6;
        static inline const std::size_t IN_6 = 7;
        static inline const std::size_t IN_7 = 8;
        static inline const std::size_t CLOCK = 9;
        static inline const std::size_t INHIBIT = 10;
        // ------ PINS ------
        LoggerComponent();
        LoggerComponent(LoggerComponent const &other);
        ~LoggerComponent() override;
        void beforeSimulation(std::size_t tick) override;
        void internalSimulate(std::size_t tick) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}