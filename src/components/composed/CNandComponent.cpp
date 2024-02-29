/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "CNandComponent.hpp"
#include "../NotComponent.hpp"
#include "../AndComponent.hpp"

using namespace nts::Components;

CNandComponent::CNandComponent(): ComposedComponent(3, "nand", 2)
{
    _internal["A"] = new AndComponent();
    _internal["B"] = new NotComponent();
    this->setPinMode(OUT, PinMode::OUTPUT);
    this->setInternalLink(IN_1, *_internal["A"], AndComponent::IN_1);
    this->setInternalLink(IN_2, *_internal["A"], AndComponent::IN_2);
    _internal["A"]->setLink(AndComponent::OUT, *_internal["B"], NotComponent::IN);
    this->setInternalLink(OUT, *_internal["B"], NotComponent::OUT);
}

nts::Tristate CNandComponent::compute(std::size_t pin)
{
    beforeCompute(pin)
    if (pin == OUT)
        return _internal["B"]->compute(NotComponent::OUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> CNandComponent::clone() const
{
    return std::make_unique<CNandComponent>();
}