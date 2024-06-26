/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "CNorComponent.hpp"
#include "../NotComponent.hpp"
#include "../OrComponent.hpp"

using namespace nts::Components;

CNorComponent::CNorComponent(): ComposedComponent(3, "nor", 2)
{
    _internal["A"] = new OrComponent();
    _internal["B"] = new NotComponent();
    this->setPinMode(OUT, PinMode::OUTPUT);
    this->setInternalLink(IN_1, *_internal["A"], OrComponent::IN_1);
    this->setInternalLink(IN_2, *_internal["A"], OrComponent::IN_2);
    _internal["A"]->setLink(OrComponent::OUT, *_internal["B"], NotComponent::IN);
    this->setInternalLink(OUT, *_internal["B"], NotComponent::OUT);
}

nts::Tristate CNorComponent::internalCompute(std::size_t pin) {
    return _internal["B"]->compute(NotComponent::OUT);
}

std::unique_ptr<nts::IComponent> CNorComponent::clone() const
{
    return std::make_unique<CNorComponent>();
}
