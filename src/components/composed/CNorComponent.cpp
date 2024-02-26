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

CNorComponent::CNorComponent(): ComposedComponent(3, 2)
{
    _internal["A"] = new OrComponent();
    _internal["B"] = new NotComponent();
    this->setPinMode(3, PinMode::OUTPUT);
    this->setLink(1, *_internal["A"], 1);
    this->setLink(2, *_internal["A"], 2);
    _internal["A"]->setLink(3, *_internal["B"], 1);
    this->setLink(3, *_internal["B"], 2);
}

nts::Tristate CNorComponent::compute(std::size_t pin)
{
    if (pin == 3)
        return _internal["B"]->compute(2);
    return UNDEFINED;
}

CNorComponent *CNorComponent::clone() const
{
    return new CNorComponent();
}

