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
    this->setPinMode(1, PinMode::OUTPUT);
}

nts::Tristate InputComponent::compute(std::size_t pin) {
    if (pin != 1)
        return UNDEFINED;
    return _value;
}

void InputComponent::setValue(Tristate value) {
    _value = value;
}

InputComponent *InputComponent::clone() const {
    return new InputComponent();
}
