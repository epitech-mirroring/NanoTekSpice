/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "P4512Component.hpp"
using namespace nts::Components;

P4512Component::P4512Component() : AbstractComponent(16, "4512")
{
    this->setPinMode(Z, PinMode::OUTPUT);
}

nts::Tristate P4512Component::internalCompute(std::size_t pin) {
    (void) pin;

    nts::Tristate inhibit = this->computeInput(INHIBIT);
    nts::Tristate oe = this->computeInput(OE);
    nts::Tristate a = this->computeInput(A);
    nts::Tristate b = this->computeInput(B);
    nts::Tristate c = this->computeInput(C);

    // If any of the inputs are undefined we cannot be sure of the output
    if (a == nts::UNDEFINED || b == nts::UNDEFINED || c == nts::UNDEFINED || inhibit == nts::UNDEFINED || oe == nts::UNDEFINED) {
        return nts::UNDEFINED;
    }

    if (oe == nts::TRUE) {
        return nts::UNDEFINED;
    }

    if (inhibit == nts::TRUE) {
        return nts::FALSE;
    }

    if (a == nts::FALSE && b == nts::FALSE && c == nts::FALSE) {
        return this->computeInput(X0);
    } else if (a == nts::TRUE && b == nts::FALSE && c == nts::FALSE) {
        return this->computeInput(X1);
    } else if (a == nts::FALSE && b == nts::TRUE && c == nts::FALSE) {
        return this->computeInput(X2);
    } else if (a == nts::TRUE && b == nts::TRUE && c == nts::FALSE) {
        return this->computeInput(X3);
    } else if (a == nts::FALSE && b == nts::FALSE && c == nts::TRUE) {
        return this->computeInput(X4);
    } else if (a == nts::TRUE && b == nts::FALSE && c == nts::TRUE) {
        return this->computeInput(X5);
    } else if (a == nts::FALSE && b == nts::TRUE && c == nts::TRUE) {
        return this->computeInput(X6);
    } else if (a == nts::TRUE && b == nts::TRUE && c == nts::TRUE) {
        return this->computeInput(X7);
    }
}

std::unique_ptr<nts::IComponent> P4512Component::clone() const {
    return std::make_unique<P4512Component>(*this);
}
