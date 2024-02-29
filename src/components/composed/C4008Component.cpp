/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C4008Component.hpp"
#include "C7482Component.hpp"

using namespace nts::Components;

C4008Component::C4008Component(): ComposedComponent(16, 4) {
    _internal["A"] = new C7482Component(); // 2 bit adder
    _internal["B"] = new C7482Component(); // 2 bit adder
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(Y3, PinMode::OUTPUT);
    this->setPinMode(Y4, PinMode::OUTPUT);
    this->setPinMode(COUT, PinMode::OUTPUT);
    this->setLink(A1, *_internal["A"], C7482Component::A1);
    this->setLink(B1, *_internal["A"], C7482Component::B1);
    this->setLink(A2, *_internal["A"], C7482Component::A2);
    this->setLink(B2, *_internal["A"], C7482Component::B2);
    this->setLink(CIN, *_internal["A"], C7482Component::CIN);
    this->setLink(Y1, *_internal["A"], C7482Component::Y1);
    this->setLink(Y2, *_internal["A"], C7482Component::Y2);
    _internal["A"]->setLink(C7482Component::COUT, *_internal["B"], C7482Component::CIN);
    this->setLink(A3, *_internal["B"], C7482Component::A1);
    this->setLink(B3, *_internal["B"], C7482Component::B1);
    this->setLink(A4, *_internal["B"], C7482Component::A2);
    this->setLink(B4, *_internal["B"], C7482Component::B2);
    this->setLink(COUT, *_internal["B"], C7482Component::COUT);
    this->setLink(Y3, *_internal["B"], C7482Component::Y1);
    this->setLink(Y4, *_internal["B"], C7482Component::Y2);
}

nts::Tristate C4008Component::compute(std::size_t pin) {
    if (pin == Y1)
        return _internal["A"]->compute(C7482Component::Y1);
    if (pin == Y2)
        return _internal["A"]->compute(C7482Component::Y2);
    if (pin == Y3)
        return _internal["B"]->compute(C7482Component::Y1);
    if (pin == Y4)
        return _internal["B"]->compute(C7482Component::Y2);
    if (pin == COUT)
        return _internal["B"]->compute(C7482Component::COUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> C4008Component::clone() const {
    return std::make_unique<C4008Component>();
}
