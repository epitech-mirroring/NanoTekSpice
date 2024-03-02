/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C4001Component.hpp"
#include "CNorComponent.hpp"

using namespace nts::Components;

C4001Component::C4001Component(): ComposedComponent(14, "4001", 4)
{
    _internal["A"] = new CNorComponent();
    _internal["B"] = new CNorComponent();
    _internal["C"] = new CNorComponent();
    _internal["D"] = new CNorComponent();
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(Y3, PinMode::OUTPUT);
    this->setPinMode(Y4, PinMode::OUTPUT);
    this->setInternalLink(A1, *_internal["A"], CNorComponent::IN_1);
    this->setInternalLink(B1, *_internal["A"], CNorComponent::IN_2);
    this->setInternalLink(Y1, *_internal["A"], CNorComponent::OUT);
    this->setInternalLink(A2, *_internal["B"], CNorComponent::IN_1);
    this->setInternalLink(B2, *_internal["B"], CNorComponent::IN_2);
    this->setInternalLink(Y2, *_internal["B"], CNorComponent::OUT);
    this->setInternalLink(A3, *_internal["C"], CNorComponent::IN_1);
    this->setInternalLink(B3, *_internal["C"], CNorComponent::IN_2);
    this->setInternalLink(Y3, *_internal["C"], CNorComponent::OUT);
    this->setInternalLink(A4, *_internal["D"], CNorComponent::IN_1);
    this->setInternalLink(B4, *_internal["D"], CNorComponent::IN_2);
    this->setInternalLink(Y4, *_internal["D"], CNorComponent::OUT);
}

nts::Tristate C4001Component::internalCompute(std::size_t pin) {
    if (pin == Y1)
        return _internal["A"]->compute(CNorComponent::OUT);
    if (pin == Y2)
        return _internal["B"]->compute(CNorComponent::OUT);
    if (pin == Y3)
        return _internal["C"]->compute(CNorComponent::OUT);
    return _internal["D"]->compute(CNorComponent::OUT);
}

std::unique_ptr<nts::IComponent> C4001Component::clone() const
{
    return std::make_unique<C4001Component>();
}
