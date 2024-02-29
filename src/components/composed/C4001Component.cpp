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

C4001Component::C4001Component(): ComposedComponent(14, 4)
{
    _internal["A"] = new CNorComponent();
    _internal["B"] = new CNorComponent();
    _internal["C"] = new CNorComponent();
    _internal["D"] = new CNorComponent();
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(Y3, PinMode::OUTPUT);
    this->setPinMode(Y4, PinMode::OUTPUT);
    this->setLink(A1, *_internal["A"], CNorComponent::IN_1);
    this->setLink(B1, *_internal["A"], CNorComponent::IN_2);
    this->setLink(Y1, *_internal["A"], CNorComponent::OUT);
    this->setLink(A2, *_internal["B"], CNorComponent::IN_1);
    this->setLink(B2, *_internal["B"], CNorComponent::IN_2);
    this->setLink(Y2, *_internal["B"], CNorComponent::OUT);
    this->setLink(A3, *_internal["C"], CNorComponent::IN_1);
    this->setLink(B3, *_internal["C"], CNorComponent::IN_2);
    this->setLink(Y3, *_internal["C"], CNorComponent::OUT);
    this->setLink(A4, *_internal["D"], CNorComponent::IN_1);
    this->setLink(B4, *_internal["D"], CNorComponent::IN_2);
    this->setLink(Y4, *_internal["D"], CNorComponent::OUT);
}

nts::Tristate C4001Component::compute(std::size_t pin)
{
    if (pin == Y1)
        return _internal["A"]->compute(CNorComponent::OUT);
    if (pin == Y2)
        return _internal["B"]->compute(CNorComponent::OUT);
    if (pin == Y3)
        return _internal["C"]->compute(CNorComponent::OUT);
    if (pin == Y4)
        return _internal["D"]->compute(CNorComponent::OUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> C4001Component::clone() const
{
    return std::make_unique<C4001Component>();
}
