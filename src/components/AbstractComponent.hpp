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
#include <vector>

namespace nts::Components {
    enum PinMode {
        INPUT,
        OUTPUT
    };
    typedef std::tuple<IComponent *, std::size_t, bool> Link;
    typedef std::tuple<PinMode, std::vector<Link>> Pin;

    class AbstractComponent : public IComponent {
    protected:
        std::string _name;
        AbstractComponent(std::size_t nbPins, const std::string &name);

        void setPinMode(std::size_t pin, PinMode type);

        [[nodiscard]] nts::Tristate computeInput(std::size_t pin) const;

        std::unordered_map<std::size_t, Pin> _pins;
    public:
        ~AbstractComponent() override;

        void simulate(std::size_t tick) override;

        void setLink(std::size_t pin, nts::IComponent &other,
                     std::size_t otherPin) override;

        void getLink(std::size_t pin) const;

        [[nodiscard]] bool hasPin(std::size_t pin) const;

        [[nodiscard]] PinMode getPinMode(std::size_t pin) const;

        [[nodiscard]] bool isLinked(std::size_t pin) const;

        [[nodiscard]] std::size_t getParentPin(std::size_t pin, std::size_t link) const;

        [[nodiscard]] nts::IComponent *
        getLinkedComponent(std::size_t pin, std::size_t link) const;

        [[nodiscard]] bool isLinkedTo(std::size_t pin, IComponent *component) const;

#define beforeCompute(pin) if (!this->hasPin(pin)) { return UNDEFINED; } if (this->getPinMode(pin) == INPUT) { return this->computeInput(pin); }
    };
}
