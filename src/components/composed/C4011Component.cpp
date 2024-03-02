/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C4011Component.hpp"
#include "CNandComponent.hpp"

using namespace nts::Components;

C4011Component::C4011Component(): ComposedComponent(14, "4011", 4)
{
    _internal["A"] = new CNandComponent();
    _internal["B"] = new CNandComponent();
    _internal["C"] = new CNandComponent();
    _internal["D"] = new CNandComponent();
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(Y3, PinMode::OUTPUT);
    this->setPinMode(Y4, PinMode::OUTPUT);
    this->setInternalLink(A1, *_internal["A"], CNandComponent::IN_1);
    this->setInternalLink(B1, *_internal["A"], CNandComponent::IN_2);
    this->setInternalLink(Y1, *_internal["A"], CNandComponent::OUT);
    this->setInternalLink(A2, *_internal["B"], CNandComponent::IN_1);
    this->setInternalLink(B2, *_internal["B"], CNandComponent::IN_2);
    this->setInternalLink(Y2, *_internal["B"], CNandComponent::OUT);
    this->setInternalLink(A3, *_internal["C"], CNandComponent::IN_1);
    this->setInternalLink(B3, *_internal["C"], CNandComponent::IN_2);
    this->setInternalLink(Y3, *_internal["C"], CNandComponent::OUT);
    this->setInternalLink(A4, *_internal["D"], CNandComponent::IN_1);
    this->setInternalLink(B4, *_internal["D"], CNandComponent::IN_2);
    this->setInternalLink(Y4, *_internal["D"], CNandComponent::OUT);
}

nts::Tristate C4011Component::internalCompute(std::size_t pin) {
    if (pin == Y1)
        return _internal["A"]->compute(CNandComponent::OUT);
    if (pin == Y2)
        return _internal["B"]->compute(CNandComponent::OUT);
    if (pin == Y3)
        return _internal["C"]->compute(CNandComponent::OUT);
    return _internal["D"]->compute(CNandComponent::OUT);
}

std::unique_ptr<nts::IComponent> C4011Component::clone() const
{
    return std::make_unique<C4011Component>();
}
