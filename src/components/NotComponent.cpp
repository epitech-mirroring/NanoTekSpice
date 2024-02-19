/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "NotComponent.hpp"

using namespace nts::Components;

NotComponent::NotComponent(): AbstractComponent(2) {
    this->setPinMode(1, PinMode::INPUT);
    this->setPinMode(2, PinMode::OUTPUT);
}

nts::Tristate NotComponent::compute(std::size_t pin) {
    if (this->getLinkedComponent(1) == nullptr)
        return UNDEFINED;
    if (pin != 2)
        return UNDEFINED;

    Tristate a = this->getLinkedComponent(1)->compute(this->getParentPin(1));

    if (a == TRUE)
        return FALSE;
    if (a == FALSE)
        return TRUE;
    return UNDEFINED;
}

NotComponent *NotComponent::clone() const {
    return new NotComponent();
}
