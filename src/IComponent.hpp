/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <cstddef>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void            simulate(std::size_t tick) = 0;
            virtual nts::Tristate   compute(std::size_t pin) = 0;
            virtual void            setLink(std::size_t pin,
                                            nts::IComponent &other,
                                            std::size_t otherPin) = 0;
    };
}
