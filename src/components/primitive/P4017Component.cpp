/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "P4017Component.hpp"
using namespace nts::Components;

P4017Component::P4017Component() : AbstractComponent(15, "4017")
{
    this->setPinMode(Q0, PinMode::OUTPUT);
    this->setPinMode(Q1, PinMode::OUTPUT);
    this->setPinMode(Q2, PinMode::OUTPUT);
    this->setPinMode(Q3, PinMode::OUTPUT);
    this->setPinMode(Q4, PinMode::OUTPUT);
    this->setPinMode(Q5, PinMode::OUTPUT);
    this->setPinMode(Q6, PinMode::OUTPUT);
    this->setPinMode(Q7, PinMode::OUTPUT);
    this->setPinMode(Q8, PinMode::OUTPUT);
    this->setPinMode(Q9, PinMode::OUTPUT);
    this->setPinMode(QB_5_9, PinMode::OUTPUT);
}

void P4017Component::beforeSimulation(size_t tick) {
    (void)tick;

    nts::Tristate clk = this->compute(CP_0);
    this->_lastClk = clk;
}

void P4017Component::internalSimulate(std::size_t tick) {
    (void)tick;

    nts::Tristate clk = this->compute(CP_0);
    nts::Tristate cb = this->compute(CPB_1);
    nts::Tristate mr = this->compute(MR);

    if (cb == nts::FALSE) {
        if (_lastClk == nts::FALSE && clk == nts::TRUE) {
            _value++;
        }
    } else if (cb == nts::TRUE) {
        if (_lastClk == nts::TRUE && clk == nts::FALSE) {
            _value++;
        }
    }

    if (mr == nts::TRUE || _value >= 10) {
        _value = 0;
    }
}

nts::Tristate P4017Component::internalCompute(std::size_t pin) {
    if (pin == Q0) {
        return (_value == 0) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q1) {
        return (_value == 1) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q2) {
        return (_value == 2) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q3) {
        return (_value == 3) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q4) {
        return (_value == 4) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q5) {
        return (_value == 5) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q6) {
        return (_value == 6) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q7) {
        return (_value == 7) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q8) {
        return (_value == 8) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q9) {
        return (_value == 9) ? nts::TRUE : nts::FALSE;
    } else if (pin == QB_5_9) {
        return (_value >= 5) ? nts::TRUE : nts::FALSE;
    }
}

std::unique_ptr<nts::IComponent> P4017Component::clone() const
{
    return std::make_unique<P4017Component>(*this);
}
