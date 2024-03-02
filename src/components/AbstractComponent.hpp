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
        std::size_t _lastSimulationTick = -1;
        AbstractComponent(std::size_t nbPins, const std::string &name);

        void setPinMode(std::size_t pin, PinMode type);

        [[nodiscard]] nts::Tristate computeInput(std::size_t pin) const;

        std::unordered_map<std::size_t, Pin> _pins;
        std::unordered_map<std::size_t, nts::Tristate> _oldValues;
        std::unordered_map<std::size_t, bool> _computed;
    public:
        ~AbstractComponent() override;

        void simulate(std::size_t tick) final;

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

        [[nodiscard]] nts::Tristate compute(std::size_t pin) final;

        [[nodiscard]] virtual nts::Tristate internalCompute(std::size_t pin) = 0;

        virtual void internalSimulate(std::size_t tick);

        void setOldValue(std::size_t pin, nts::Tristate value);
    };
}
