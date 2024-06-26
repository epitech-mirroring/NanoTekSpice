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
    _tempValue = UNDEFINED;
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate ClockComponent::internalCompute(std::size_t pin) {
    return _value;
}

void ClockComponent::setValue(nts::Tristate value) {
    _tempValue = value;
    _hasChanged = true;
}

void ClockComponent::internalSimulate(std::size_t tick)
{
    if (_hasChanged) {
        _value = _tempValue;
        _hasChanged = false;
    } else {
        _value = !_value;
    }
}

std::unique_ptr<nts::IComponent> ClockComponent::clone() const {
    return std::make_unique<ClockComponent>();
}
