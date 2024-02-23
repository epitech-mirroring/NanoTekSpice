/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "FalseComponent.hpp"

using namespace nts::Components;

FalseComponent::FalseComponent(): AbstractComponent(1) {
    this->setPinMode(1, PinMode::OUTPUT);
}

nts::Tristate FalseComponent::compute(std::size_t pin) {
    if (pin != 1)
        return UNDEFINED;
    return FALSE;
}

FalseComponent *FalseComponent::clone() const {
    return new FalseComponent();
}
