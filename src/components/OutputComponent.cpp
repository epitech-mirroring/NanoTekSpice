/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "OutputComponent.hpp"

using namespace nts::Components;

OutputComponent::OutputComponent(): AbstractComponent(1) {
    this->_value = UNDEFINED;
    this->setPinMode(1, PinMode::INPUT);
}

nts::Tristate OutputComponent::compute(std::size_t pin) {
    if (pin != 1)
        return UNDEFINED;
    return this->_value;
}

void OutputComponent::simulate(std::size_t tick) {
    (void)tick;
    this->_value = this->getLinkedComponent(1)->compute(this->getParentPin(1));
}

OutputComponent *OutputComponent::clone() const {
    return new OutputComponent();
}