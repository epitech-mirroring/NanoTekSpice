/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C4069Component.hpp"
#include "../NotComponent.hpp"

using namespace nts::Components;

C4069Component::C4069Component(): ComposedComponent(14, "4069", 6)
{
    _internal["A"] = new NotComponent();
    _internal["B"] = new NotComponent();
    _internal["C"] = new NotComponent();
    _internal["D"] = new NotComponent();
    _internal["E"] = new NotComponent();
    _internal["F"] = new NotComponent();
    this->setPinMode(OUT_1, PinMode::OUTPUT);
    this->setPinMode(OUT_2, PinMode::OUTPUT);
    this->setPinMode(OUT_3, PinMode::OUTPUT);
    this->setPinMode(OUT_4, PinMode::OUTPUT);
    this->setPinMode(OUT_5, PinMode::OUTPUT);
    this->setPinMode(OUT_6, PinMode::OUTPUT);
    this->setInternalLink(IN_1, *_internal["A"], NotComponent::IN);
    this->setInternalLink(OUT_1, *_internal["A"], NotComponent::OUT);
    this->setInternalLink(IN_2, *_internal["B"], NotComponent::IN);
    this->setInternalLink(OUT_2, *_internal["B"], NotComponent::OUT);
    this->setInternalLink(IN_3, *_internal["C"], NotComponent::IN);
    this->setInternalLink(OUT_3, *_internal["C"], NotComponent::OUT);
    this->setInternalLink(IN_4, *_internal["D"], NotComponent::IN);
    this->setInternalLink(OUT_4, *_internal["D"], NotComponent::OUT);
    this->setInternalLink(IN_5, *_internal["E"], NotComponent::IN);
    this->setInternalLink(OUT_5, *_internal["E"], NotComponent::OUT);
    this->setInternalLink(IN_6, *_internal["F"], NotComponent::IN);
    this->setInternalLink(OUT_6, *_internal["F"], NotComponent::OUT);
}

nts::Tristate C4069Component::internalCompute(std::size_t pin) {
    if (pin == OUT_1)
        return _internal["A"]->compute(NotComponent::OUT);
    if (pin == OUT_2)
        return _internal["B"]->compute(NotComponent::OUT);
    if (pin == OUT_3)
        return _internal["C"]->compute(NotComponent::OUT);
    if (pin == OUT_4)
        return _internal["D"]->compute(NotComponent::OUT);
    if (pin == OUT_5)
        return _internal["E"]->compute(NotComponent::OUT);
    if (pin == OUT_6)
        return _internal["F"]->compute(NotComponent::OUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> C4069Component::clone() const
{
    return std::make_unique<C4069Component>();
}
