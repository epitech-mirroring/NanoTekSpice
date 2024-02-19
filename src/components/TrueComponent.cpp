/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "TrueComponent.hpp"

using namespace nts::Components;

TrueComponent::TrueComponent(): AbstractComponent(1) {
    this->setPinMode(1, PinMode::OUTPUT);
}

nts::Tristate TrueComponent::compute(std::size_t pin) {
    if (pin != 1)
        return UNDEFINED;
    return TRUE;
}

TrueComponent *TrueComponent::clone() const {
    return new TrueComponent();
}
