/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ClockComponent.hpp"

using namespace nts::Components;

ClockComponent::ClockComponent(): InputComponent() {
    _value = UNDEFINED;
    this->setPinMode(1, PinMode::OUTPUT);
}

nts::Tristate ClockComponent::compute(std::size_t pin) {
    if (pin != 1)
        return UNDEFINED;
    return _value;
}

std::unique_ptr<nts::IComponent> ClockComponent::clone() const {
    return std::make_unique<ClockComponent>();
}

void ClockComponent::simulate(std::size_t tick)
{
    for (size_t i = 0; i < tick; i++) {
        _value = !_value;
    }
}

void ClockComponent::setValue(nts::Tristate value) {
    _value = value;
}
