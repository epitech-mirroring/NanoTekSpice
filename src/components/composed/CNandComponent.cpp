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

CNandComponent::CNandComponent(): ComposedComponent(3, 2)
{
    _internal["A"] = new AndComponent();
    _internal["B"] = new NotComponent();
    this->setPinMode(3, PinMode::OUTPUT);
    this->setLink(1, *_internal["A"], 1);
    this->setLink(2, *_internal["A"], 2);
    _internal["A"]->setLink(3, *_internal["B"], 1);
    this->setLink(3, *_internal["B"], 2);
}

nts::Tristate CNandComponent::compute(std::size_t pin)
{
    if (pin == 3)
        return _internal["B"]->compute(2);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> CNandComponent::clone() const
{
    return std::make_unique<CNandComponent>();
}