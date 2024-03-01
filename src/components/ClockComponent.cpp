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
    _hasChanged = false;
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate ClockComponent::internalCompute(std::size_t pin) {
    if (pin != OUT)
        return UNDEFINED;
    return _value;
}

void ClockComponent::setValue(nts::Tristate value) {
    _tempValue = value;
    _hasChanged = true;
}

void ClockComponent::simulate(std::size_t tick)
{
    if (_hasChanged) {
        _value = _tempValue;
        _hasChanged = false;
    } else {
        for (size_t i = 0; i < tick; i++) {
            _value = !_value;
        }
    }
}

std::unique_ptr<nts::IComponent> ClockComponent::clone() const {
    return std::make_unique<ClockComponent>();
}
