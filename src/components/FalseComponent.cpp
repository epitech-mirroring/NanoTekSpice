/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "FalseComponent.hpp"

using namespace nts::Components;

FalseComponent::FalseComponent(): AbstractComponent(1, "false") {
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate FalseComponent::internalCompute(std::size_t pin) {
    (void)pin;
    return FALSE;
}

std::unique_ptr<nts::IComponent> FalseComponent::clone() const {
    return std::make_unique<FalseComponent>();
}
