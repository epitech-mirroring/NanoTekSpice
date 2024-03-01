/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "OrComponent.hpp"

using namespace nts::Components;

OrComponent::OrComponent(): AbstractComponent(3, "or") {
    this->setPinMode(IN_1, PinMode::INPUT);
    this->setPinMode(IN_2, PinMode::INPUT);
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate OrComponent::compute(std::size_t pin) {
    beforeCompute(pin)
    if (pin != OUT)
        return UNDEFINED;

    Tristate a = this->computeInput(IN_1);
    Tristate b = this->computeInput(IN_2);
    if (a == TRUE || b == TRUE)
        return TRUE;
    if (a == UNDEFINED || b == UNDEFINED)
        return UNDEFINED;
    return FALSE;
}

std::unique_ptr<nts::IComponent> OrComponent::clone() const {
    return std::make_unique<OrComponent>();
}
