/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "AndComponent.hpp"

using namespace nts::Components;

AndComponent::AndComponent()
    : AbstractComponent(3, "and")
{
    this->setPinMode(IN_1, PinMode::INPUT);
    this->setPinMode(IN_2, PinMode::INPUT);
    this->setPinMode(OUT, PinMode::OUTPUT);
}

nts::Tristate AndComponent::internalCompute(std::size_t pin) {
    (void)pin;
    Tristate a = this->computeInput(IN_1);
    Tristate b = this->computeInput(IN_2);
    if (a == FALSE || b == FALSE)
        return FALSE;
    if (a == UNDEFINED || b == UNDEFINED)
        return UNDEFINED;
    return TRUE;
}

std::unique_ptr<nts::IComponent> AndComponent::clone() const
{
    return std::make_unique<AndComponent>();
}
