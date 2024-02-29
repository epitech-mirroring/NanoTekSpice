/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "TrueComponent.hpp"

using namespace nts::Components;

TrueComponent::TrueComponent(): AbstractComponent(1, "true") {
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate TrueComponent::compute(std::size_t pin) {
    beforeCompute(pin)
    if (pin != OUT)
        return UNDEFINED;
    return TRUE;
}

std::unique_ptr<nts::IComponent> TrueComponent::clone() const {
    return std::make_unique<TrueComponent>();
}
