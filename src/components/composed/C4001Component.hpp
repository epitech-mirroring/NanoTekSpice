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
    class C4001Component: public ComposedComponent {
    public:
        // ------ PINS ------
        static constexpr std::size_t A1 = 1;
        static constexpr std::size_t B1 = 2;
        static constexpr std::size_t Y1 = 3;
        static constexpr std::size_t Y2 = 4;
        static constexpr std::size_t A2 = 5;
        static constexpr std::size_t B2 = 6;
        static constexpr std::size_t VSS = 7;
        static constexpr std::size_t A3 = 8;
        static constexpr std::size_t B3 = 9;
        static constexpr std::size_t Y3 = 10;
        static constexpr std::size_t Y4 = 11;
        static constexpr std::size_t A4 = 12;
        static constexpr std::size_t B4 = 13;
        static constexpr std::size_t VDD = 14;
        // ------ PINS ------
        C4001Component();
        ~C4001Component() override = default;
        Tristate internalCompute(std::size_t pin) override;
        [[nodiscard]] std::unique_ptr<IComponent> clone() const override;
    };
}
