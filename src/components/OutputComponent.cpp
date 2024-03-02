/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "OutputComponent.hpp"

using namespace nts::Components;

OutputComponent::OutputComponent(): AbstractComponent(1, "output") {
    this->_value = UNDEFINED;
    this->setPinMode(IN, PinMode::INPUT);
}

void OutputComponent::internalSimulate(std::size_t tick) {
    this->_value = this->computeInput(IN);
}

std::unique_ptr<nts::IComponent> OutputComponent::clone() const {
    return std::make_unique<OutputComponent>();
}
