/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "../IComponent.hpp"
#include <unordered_map>
#include <tuple>
#include <string>
#include <memory>

namespace nts::Components {
    enum PinMode {
        INPUT,
        OUTPUT
    };

    class AbstractComponent : public IComponent {
    private:
        std::unordered_map<std::size_t, std::tuple<IComponent *, PinMode, std::size_t>> _pins;
    protected:
        explicit AbstractComponent(std::size_t nbPins);

        void setPinMode(std::size_t pin, PinMode type);

    public:
        ~AbstractComponent() override = default;

        void simulate(std::size_t tick) override;

        void setLink(std::size_t pin, nts::IComponent &other,
                     std::size_t otherPin) override;

        void getLink(std::size_t pin) const;

        [[nodiscard]] bool hasPin(std::size_t pin) const;

        [[nodiscard]] PinMode getPinMode(std::size_t pin) const;

        [[nodiscard]] bool isLinked(std::size_t pin) const;

        [[nodiscard]] std::size_t getParentPin(std::size_t pin) const;

        [[nodiscard]] nts::IComponent *
        getLinkedComponent(std::size_t pin) const;
    };
}
