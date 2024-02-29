/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C4030Component.hpp"
#include "../XorComponent.hpp"

using namespace nts::Components;

C4030Component::C4030Component(): ComposedComponent(14, "4030", 4)
{
    _internal["A"] = new XorComponent();
    _internal["B"] = new XorComponent();
    _internal["C"] = new XorComponent();
    _internal["D"] = new XorComponent();
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(Y3, PinMode::OUTPUT);
    this->setPinMode(Y4, PinMode::OUTPUT);
    this->setInternalLink(A1, *_internal["A"], XorComponent::IN_1);
    this->setInternalLink(B1, *_internal["A"], XorComponent::IN_2);
    this->setInternalLink(Y1, *_internal["A"], XorComponent::OUT);
    this->setInternalLink(A2, *_internal["B"], XorComponent::IN_1);
    this->setInternalLink(B2, *_internal["B"], XorComponent::IN_2);
    this->setInternalLink(Y2, *_internal["B"], XorComponent::OUT);
    this->setInternalLink(A3, *_internal["C"], XorComponent::IN_1);
    this->setInternalLink(B3, *_internal["C"], XorComponent::IN_2);
    this->setInternalLink(Y3, *_internal["C"], XorComponent::OUT);
    this->setInternalLink(A4, *_internal["D"], XorComponent::IN_1);
    this->setInternalLink(B4, *_internal["D"], XorComponent::IN_2);
    this->setInternalLink(Y4, *_internal["D"], XorComponent::OUT);
}

nts::Tristate C4030Component::compute(std::size_t pin)
{
    beforeCompute(pin)
    if (pin == Y1)
        return _internal["A"]->compute(XorComponent::OUT);
    if (pin == Y2)
        return _internal["B"]->compute(XorComponent::OUT);
    if (pin == Y3)
        return _internal["C"]->compute(XorComponent::OUT);
    if (pin == Y4)
        return _internal["D"]->compute(XorComponent::OUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> C4030Component::clone() const
{
    return std::make_unique<C4030Component>();
}
