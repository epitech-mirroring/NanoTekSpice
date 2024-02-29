/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "InputComponent.hpp"

using namespace nts::Components;

InputComponent::InputComponent(): AbstractComponent(1) {
    _value = UNDEFINED;
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate InputComponent::compute(std::size_t pin) {
    if (pin != OUT)
        return UNDEFINED;
    return _value;
}

void InputComponent::setValue(Tristate value) {
    _value = value;
}

std::unique_ptr<nts::IComponent> InputComponent::clone() const {
    return std::make_unique<InputComponent>();
}
