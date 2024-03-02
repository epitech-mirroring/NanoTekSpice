/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "InputComponent.hpp"

using namespace nts::Components;

InputComponent::InputComponent(): AbstractComponent(1, "input") {
    _value = UNDEFINED;
    _tempValue = UNDEFINED;
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate InputComponent::internalCompute(std::size_t pin) {
    return _value;
}

void InputComponent::setValue(Tristate value) {
    _tempValue = value;
}

void InputComponent::internalSimulate(std::size_t tick) {
    _value = _tempValue;
}

std::unique_ptr<nts::IComponent> InputComponent::clone() const {
    return std::make_unique<InputComponent>();
}
