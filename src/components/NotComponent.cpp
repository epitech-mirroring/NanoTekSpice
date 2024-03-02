/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "NotComponent.hpp"

using namespace nts::Components;

NotComponent::NotComponent(): AbstractComponent(2, "not") {
    this->setPinMode(IN, PinMode::INPUT);
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate NotComponent::internalCompute(std::size_t pin) {
    (void)pin;
    Tristate a = this->computeInput(IN);

    if (a == TRUE)
        return FALSE;
    if (a == FALSE)
        return TRUE;
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> NotComponent::clone() const {
    return std::make_unique<NotComponent>();
}
