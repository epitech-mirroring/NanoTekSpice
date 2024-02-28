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

C4069Component::C4069Component(): ComposedComponent(14, 6)
{
    _internal["A"] = new NotComponent();
    _internal["B"] = new NotComponent();
    _internal["C"] = new NotComponent();
    _internal["D"] = new NotComponent();
    _internal["E"] = new NotComponent();
    _internal["F"] = new NotComponent();
    this->setPinMode(2, PinMode::OUTPUT);
    this->setPinMode(4, PinMode::OUTPUT);
    this->setPinMode(6, PinMode::OUTPUT);
    this->setPinMode(8, PinMode::OUTPUT);
    this->setPinMode(10, PinMode::OUTPUT);
    this->setPinMode(12, PinMode::OUTPUT);
    this->setLink(1, *_internal["A"], 1);
    this->setLink(2, *_internal["A"], 2);
    this->setLink(3, *_internal["B"], 1);
    this->setLink(4, *_internal["B"], 2);
    this->setLink(5, *_internal["C"], 1);
    this->setLink(6, *_internal["C"], 2);
    this->setLink(9, *_internal["D"], 1);
    this->setLink(8, *_internal["D"], 2);
    this->setLink(11, *_internal["E"], 1);
    this->setLink(10, *_internal["E"], 2);
    this->setLink(13, *_internal["F"], 1);
    this->setLink(12, *_internal["F"], 2);
}

nts::Tristate C4069Component::compute(std::size_t pin)
{
    if (pin == 2)
        return _internal["A"]->compute(2);
    if (pin == 4)
        return _internal["B"]->compute(2);
    if (pin == 6)
        return _internal["C"]->compute(2);
    if (pin == 8)
        return _internal["D"]->compute(2);
    if (pin == 10)
        return _internal["E"]->compute(2);
    if (pin == 12)
        return _internal["F"]->compute(2);
    return UNDEFINED;
}

C4069Component *C4069Component::clone() const
{
    return new C4069Component();
}
