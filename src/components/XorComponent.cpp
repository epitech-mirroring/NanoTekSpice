/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "XorComponent.hpp"

using namespace nts::Components;

XorComponent::XorComponent(): AbstractComponent(3)
{
    this->setPinMode(1, PinMode::INPUT);
    this->setPinMode(2, PinMode::INPUT);
    this->setPinMode(3, PinMode::OUTPUT);
}

nts::Tristate XorComponent::compute(std::size_t pin)
{
    if (this->getLinkedComponent(1) == nullptr || this->getLinkedComponent(2) == nullptr)
        return UNDEFINED;
    if (pin != 3)
        return UNDEFINED;

    Tristate a = this->getLinkedComponent(1)->compute(this->getParentPin(1));
    Tristate b = this->getLinkedComponent(2)->compute(this->getParentPin(2));
    if ((a == TRUE && b == FALSE) || (a == FALSE && b == TRUE))
        return TRUE;
    if (a == UNDEFINED || b == UNDEFINED)
        return UNDEFINED;
    return FALSE;
}

XorComponent *XorComponent::clone() const
{
    return new XorComponent();
}
