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
    this->setPinMode(IN, PinMode::INPUT);
}

nts::Tristate OutputComponent::compute(std::size_t pin) {
    if (pin != IN)
        return UNDEFINED;
    return this->_value;
}

void OutputComponent::simulate(std::size_t tick) {
    (void)tick;
    this->_value = this->getLinkedComponent(IN)->compute(this->getParentPin(IN));
}

std::unique_ptr<nts::IComponent> OutputComponent::clone() const {
    return std::make_unique<OutputComponent>();
}
