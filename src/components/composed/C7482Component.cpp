/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "C7482Component.hpp"
#include "../XorComponent.hpp"
#include "../AndComponent.hpp"
#include "../OrComponent.hpp"
#include <iostream>

using namespace nts::Components;

C7482Component::C7482Component(): ComposedComponent(14, "7482", 10) {
    _internal["g00"] = new XorComponent();
    _internal["g10"] = new AndComponent();
    _internal["g01"] = new XorComponent();
    _internal["g11"] = new AndComponent();
    _internal["g20"] = new XorComponent();
    _internal["g30"] = new AndComponent();
    _internal["g40"] = new OrComponent();
    _internal["g21"] = new XorComponent();
    _internal["g31"] = new AndComponent();
    _internal["g41"] = new OrComponent();
    this->setPinMode(Y1, PinMode::OUTPUT);
    this->setPinMode(Y2, PinMode::OUTPUT);
    this->setPinMode(COUT, PinMode::OUTPUT);
    this->setInternalLink(C7482Component::A1, *_internal["g00"], XorComponent::IN_1);
    this->setInternalLink(C7482Component::A1, *_internal["g10"], AndComponent::IN_1);
    this->setInternalLink(C7482Component::B1, *_internal["g00"], XorComponent::IN_2);
    this->setInternalLink(C7482Component::B1, *_internal["g10"], AndComponent::IN_2);
    this->setInternalLink(C7482Component::A2, *_internal["g01"], XorComponent::IN_1);
    this->setInternalLink(C7482Component::A2, *_internal["g11"], AndComponent::IN_1);
    this->setInternalLink(C7482Component::B2, *_internal["g01"], XorComponent::IN_2);
    this->setInternalLink(C7482Component::B2, *_internal["g11"], AndComponent::IN_2);
    this->setInternalLink(C7482Component::CIN, *_internal["g20"], XorComponent::IN_1);
    this->setInternalLink(C7482Component::CIN, *_internal["g30"], AndComponent::IN_1);
    _internal["g00"]->setLink(XorComponent::OUT, *_internal["g20"], XorComponent::IN_2);
    _internal["g00"]->setLink(AndComponent::OUT, *_internal["g30"], AndComponent::IN_2);
    this->setInternalLink(C7482Component::Y1, *_internal["g20"], XorComponent::OUT);
    _internal["g30"]->setLink(AndComponent::OUT, *_internal["g40"], OrComponent::IN_1);
    _internal["g10"]->setLink(AndComponent::OUT, *_internal["g40"], OrComponent::IN_2);
    _internal["g40"]->setLink(OrComponent::OUT, *_internal["g21"], XorComponent::IN_1);
    _internal["g40"]->setLink(OrComponent::OUT, *_internal["g31"], AndComponent::IN_1);
    _internal["g01"]->setLink(XorComponent::OUT, *_internal["g21"], XorComponent::IN_2);
    _internal["g01"]->setLink(XorComponent::OUT, *_internal["g31"], XorComponent::IN_2);
    this->setInternalLink(C7482Component::Y2, *_internal["g21"], XorComponent::OUT);
    _internal["g31"]->setLink(AndComponent::OUT, *_internal["g41"], OrComponent::IN_1);
    _internal["g11"]->setLink(AndComponent::OUT, *_internal["g41"], OrComponent::IN_2);
    this->setInternalLink(C7482Component::COUT, *_internal["g41"], OrComponent::OUT);
}

nts::Tristate C7482Component::compute(std::size_t pin) {
    beforeCompute(pin)
    if (pin == Y1)
        return _internal["g20"]->compute(XorComponent::OUT);
    if (pin == Y2)
        return _internal["g21"]->compute(XorComponent::OUT);
    if (pin == COUT)
        return _internal["g41"]->compute(OrComponent::OUT);
    return UNDEFINED;
}

std::unique_ptr<nts::IComponent> C7482Component::clone() const {
    return std::make_unique<C7482Component>();
}
