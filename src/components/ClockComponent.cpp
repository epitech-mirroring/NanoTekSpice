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
    this->_name = "clock";
    _value = UNDEFINED;
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate ClockComponent::internalCompute(std::size_t pin) {
    if (pin != OUT)
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
