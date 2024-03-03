/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "P4094Component.hpp"
using namespace nts::Components;

P4094Component::P4094Component() : AbstractComponent(16, "4094")
{
    this->setPinMode(Q1, PinMode::OUTPUT);
    this->setPinMode(Q2, PinMode::OUTPUT);
    this->setPinMode(Q3, PinMode::OUTPUT);
    this->setPinMode(Q4, PinMode::OUTPUT);
    this->setPinMode(Q5, PinMode::OUTPUT);
    this->setPinMode(Q6, PinMode::OUTPUT);
    this->setPinMode(Q7, PinMode::OUTPUT);
    this->setPinMode(Q8, PinMode::OUTPUT);
    this->setPinMode(QS, PinMode::OUTPUT);
    this->setPinMode(QS_PRIME, PinMode::OUTPUT);

    this->_lastClockState = nts::UNDEFINED;
    for (auto & value : this->values)
        value = nts::UNDEFINED;
    this->qs = nts::UNDEFINED;
    this->qs_prime = nts::UNDEFINED;
}

void P4094Component::beforeSimulation(size_t tick)
{
    (void) tick;

    nts::Tristate clock = this->computeInput(CLOCK);
    this->_lastClockState = clock;
}

void P4094Component::internalSimulate(std::size_t tick)
{
    (void) tick;

    nts::Tristate clock = this->computeInput(CLOCK);
    nts::Tristate strobe = this->computeInput(STROBE);

    if (this->_lastClockState == nts::FALSE && clock == nts::TRUE) {
        this->qs = this->values[6];
        if (strobe == nts::TRUE) {
            for (int i = 7; i > 0; i--) {
                this->values[i] = this->values[i - 1];
            }
            this->values[0] = this->computeInput(DATA);
        }
    }
    if (this->_lastClockState == nts::TRUE && clock == nts::FALSE) {
        this->qs_prime = this->qs;
    }
}

nts::Tristate P4094Component::internalCompute(std::size_t pin)
{
    nts::Tristate oe = this->computeInput(OE);

    if (oe == nts::FALSE) {
        return nts::UNDEFINED;
    }

    switch (pin) {
        case Q1:
            return this->values[0];
        case Q2:
            return this->values[1];
        case Q3:
            return this->values[2];
        case Q4:
            return this->values[3];
        case Q5:
            return this->values[4];
        case Q6:
            return this->values[5];
        case Q7:
            return this->values[6];
        case Q8:
            return this->values[7];
        case QS:
            return this->qs;
        default:
        case QS_PRIME:
            return this->qs_prime;
    }
}

[[nodiscard]] std::unique_ptr<nts::IComponent> P4094Component::clone() const
{
    return std::make_unique<P4094Component>(*this);
}
