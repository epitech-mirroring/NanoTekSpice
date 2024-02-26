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

C4071Component::C4071Component(): ComposedComponent(14, 4)
{
    _internal["A"] = new OrComponent();
    _internal["B"] = new OrComponent();
    _internal["C"] = new OrComponent();
    _internal["D"] = new OrComponent();
    this->setPinMode(3, PinMode::OUTPUT);
    this->setPinMode(4, PinMode::OUTPUT);
    this->setPinMode(10, PinMode::OUTPUT);
    this->setPinMode(11, PinMode::OUTPUT);
    this->setLink(1, *_internal["A"], 1);
    this->setLink(2, *_internal["A"], 2);
    this->setLink(5, *_internal["B"], 1);
    this->setLink(6, *_internal["B"], 2);
    this->setLink(8, *_internal["C"], 1);
    this->setLink(9, *_internal["C"], 2);
    this->setLink(12, *_internal["D"], 1);
    this->setLink(13, *_internal["D"], 2);
    this->setLink(3, *_internal["A"], 3);
    this->setLink(4, *_internal["B"], 3);
    this->setLink(10, *_internal["C"], 3);
    this->setLink(11, *_internal["D"], 3);
}

nts::Tristate C4071Component::compute(std::size_t pin)
{
    if (pin == 3)
        return _internal["A"]->compute(3);
    if (pin == 4)
        return _internal["B"]->compute(3);
    if (pin == 10)
        return _internal["C"]->compute(3);
    if (pin == 11)
        return _internal["D"]->compute(3);
    return UNDEFINED;
}

C4071Component *C4071Component::clone() const
{
    return new C4071Component();
}
