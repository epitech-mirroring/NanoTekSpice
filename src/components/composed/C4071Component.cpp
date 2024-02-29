/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C4071Component.hpp"
#include "../OrComponent.hpp"

using namespace nts::Components;

C4071Component::C4071Component(): ComposedComponent(14, "4071", 4)
{
    _internal["A"] = new OrComponent();
    _internal["B"] = new OrComponent();
    _internal["C"] = new OrComponent();
    _internal["D"] = new OrComponent();
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(Y3, PinMode::OUTPUT);
    this->setPinMode(Y4, PinMode::OUTPUT);
    this->setInternalLink(A1, *_internal["A"], OrComponent::IN_1);
    this->setInternalLink(B1, *_internal["A"], OrComponent::IN_2);
    this->setInternalLink(Y1, *_internal["A"], OrComponent::OUT);
    this->setInternalLink(A2, *_internal["B"], OrComponent::IN_1);
    this->setInternalLink(B2, *_internal["B"], OrComponent::IN_2);
    this->setInternalLink(Y2, *_internal["B"], OrComponent::OUT);
    this->setInternalLink(A3, *_internal["C"], OrComponent::IN_1);
    this->setInternalLink(B3, *_internal["C"], OrComponent::IN_2);
    this->setInternalLink(Y3, *_internal["C"], OrComponent::OUT);
    this->setInternalLink(A4, *_internal["D"], OrComponent::IN_1);
    this->setInternalLink(B4, *_internal["D"], OrComponent::IN_2);
    this->setInternalLink(Y4, *_internal["D"], OrComponent::OUT);
}

nts::Tristate C4071Component::compute(std::size_t pin)
{
    beforeCompute(pin)
    if (pin == Y1)
        return _internal["A"]->compute(OrComponent::OUT);
    if (pin == Y2)
        return _internal["B"]->compute(OrComponent::OUT);
    if (pin == Y3)
        return _internal["C"]->compute(OrComponent::OUT);
    if (pin == Y4)
        return _internal["D"]->compute(OrComponent::OUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> C4071Component::clone() const
{
    return std::make_unique<C4071Component>();
}
