/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "P4514Component.hpp"
using namespace nts::Components;

P4514Component::P4514Component(): AbstractComponent(24, "4514")
{
    this->setPinMode(P4514Component::S0, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S1, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S2, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S3, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S4, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S5, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S6, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S7, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S8, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S9, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S10, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S11, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S12, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S13, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S14, PinMode::OUTPUT);
    this->setPinMode(P4514Component::S15, PinMode::OUTPUT);

    this->a = UNDEFINED;
    this->b = UNDEFINED;
    this->c = UNDEFINED;
    this->d = UNDEFINED;
}

static nts::Tristate computeResult(nts::Tristate data[4], nts::Tristate d, nts::Tristate c, nts::Tristate b, nts::Tristate a)
{
    if (data[0] == d && data[1] == c && data[2] == b && data[3] == a) {
        return nts::Tristate::TRUE;
    }
    return nts::Tristate::FALSE;
}

nts::Tristate P4514Component::internalCompute(std::size_t pin)
{
    Tristate store = this->computeInput(P4514Component::STORE);
    Tristate inA = this->computeInput(P4514Component::IN_A);
    Tristate inB = this->computeInput(P4514Component::IN_B);
    Tristate inC = this->computeInput(P4514Component::IN_C);
    Tristate inD = this->computeInput(P4514Component::IN_D);

    // If store is true, store the inputs
    if (store == nts::Tristate::TRUE) {
        this->a = inA;
        this->b = inB;
        this->c = inC;
        this->d = inD;
    }


    Tristate inhibit = this->computeInput(P4514Component::INHIBIT);
    // If inhibit is true, return false
    if (inhibit == nts::Tristate::TRUE) {
        return nts::Tristate::FALSE;
    }

    // If any of the inputs are undefined, return undefined bc we can't compute
    if (this->a == nts::Tristate::UNDEFINED || this->b == nts::Tristate::UNDEFINED || this->c == nts::Tristate::UNDEFINED || this->d == nts::Tristate::UNDEFINED) {
        return nts::Tristate::UNDEFINED;
    }

    Tristate data[4] = {this->d, this->c, this->b, this->a};

    // Compute the output
    if (pin == P4514Component::S0) {
        return computeResult(data, FALSE, FALSE, FALSE, FALSE);
    } else if (pin == P4514Component::S1) {
        return computeResult(data, FALSE, FALSE, FALSE, TRUE);
    } else if (pin == P4514Component::S2) {
        return computeResult(data, FALSE, FALSE, TRUE, FALSE);
    } else if (pin == P4514Component::S3) {
        return computeResult(data, FALSE, FALSE, TRUE, TRUE);
    } else if (pin == P4514Component::S4) {
        return computeResult(data, FALSE, TRUE, FALSE, FALSE);
    } else if (pin == P4514Component::S5) {
        return computeResult(data, FALSE, TRUE, FALSE, TRUE);
    } else if (pin == P4514Component::S6) {
        return computeResult(data, FALSE, TRUE, TRUE, FALSE);
    } else if (pin == P4514Component::S7) {
        return computeResult(data, FALSE, TRUE, TRUE, TRUE);
    } else if (pin == P4514Component::S8) {
        return computeResult(data, TRUE, FALSE, FALSE, FALSE);
    } else if (pin == P4514Component::S9) {
        return computeResult(data, TRUE, FALSE, FALSE, TRUE);
    } else if (pin == P4514Component::S10) {
        return computeResult(data, TRUE, FALSE, TRUE, FALSE);
    } else if (pin == P4514Component::S11) {
        return computeResult(data, TRUE, FALSE, TRUE, TRUE);
    } else if (pin == P4514Component::S12) {
        return computeResult(data, TRUE, TRUE, FALSE, FALSE);
    } else if (pin == P4514Component::S13) {
        return computeResult(data, TRUE, TRUE, FALSE, TRUE);
    } else if (pin == P4514Component::S14) {
        return computeResult(data, TRUE, TRUE, TRUE, FALSE);
    } else if (pin == P4514Component::S15) {
        return computeResult(data, TRUE, TRUE, TRUE, TRUE);
    }
}

std::unique_ptr<nts::IComponent> P4514Component::clone() const
{
    return std::make_unique<P4514Component>();
}
