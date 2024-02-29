/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C4081Component.hpp"
#include "../AndComponent.hpp"

using namespace nts::Components;

C4081Component::C4081Component(): ComposedComponent(14,"4081", 4) {
    _internal["A"] = new AndComponent();
    _internal["B"] = new AndComponent();
    _internal["C"] = new AndComponent();
    _internal["D"] = new AndComponent();
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(Y3, PinMode::OUTPUT);
    this->setPinMode(Y4, PinMode::OUTPUT);
    this->setInternalLink(A1, *_internal["A"], AndComponent::IN_1);
    this->setInternalLink(B1, *_internal["A"], AndComponent::IN_2);
    this->setInternalLink(Y1, *_internal["A"], AndComponent::OUT);
    this->setInternalLink(A2, *_internal["B"], AndComponent::IN_1);
    this->setInternalLink(B2, *_internal["B"], AndComponent::IN_2);
    this->setInternalLink(Y2, *_internal["B"], AndComponent::OUT);
    this->setInternalLink(A3, *_internal["C"], AndComponent::IN_1);
    this->setInternalLink(B3, *_internal["C"], AndComponent::IN_2);
    this->setInternalLink(Y3, *_internal["C"], AndComponent::OUT);
    this->setInternalLink(A4, *_internal["D"], AndComponent::IN_1);
    this->setInternalLink(B4, *_internal["D"], AndComponent::IN_2);
    this->setInternalLink(Y4, *_internal["D"], AndComponent::OUT);
}

nts::Tristate C4081Component::compute(std::size_t pin) {
    beforeCompute(pin)
    if (pin == Y1)
        return _internal["A"]->compute(AndComponent::OUT);
    if (pin == Y2)
        return _internal["B"]->compute(AndComponent::OUT);
    if (pin == Y3)
        return _internal["C"]->compute(AndComponent::OUT);
    if (pin == Y4)
        return _internal["D"]->compute(AndComponent::OUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> C4081Component::clone() const {
    return std::make_unique<C4081Component>();
}
