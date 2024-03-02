/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "P4040Component.hpp"
using namespace nts::Components;

P4040Component::P4040Component(): AbstractComponent(16, "4040") {
    this->setPinMode(CLK, PinMode::INPUT);
    this->setPinMode(RS, PinMode::INPUT);
    this->setPinMode(Q1, PinMode::OUTPUT);
    this->setPinMode(Q2, PinMode::OUTPUT);
    this->setPinMode(Q3, PinMode::OUTPUT);
    this->setPinMode(Q4, PinMode::OUTPUT);
    this->setPinMode(Q5, PinMode::OUTPUT);
    this->setPinMode(Q6, PinMode::OUTPUT);
    this->setPinMode(Q7, PinMode::OUTPUT);
    this->setPinMode(Q8, PinMode::OUTPUT);
    this->setPinMode(Q9, PinMode::OUTPUT);
    this->setPinMode(Q10, PinMode::OUTPUT);
    this->setPinMode(Q11, PinMode::OUTPUT);
    this->setPinMode(Q12, PinMode::OUTPUT);
}

void P4040Component::beforeSimulation(size_t tick) {
    (void)tick;

    Tristate clk = this->computeInput(CLK);
    this->_lastClk = clk;
}

void P4040Component::internalSimulate(std::size_t tick) {
    (void) tick;

    Tristate clk = this->computeInput(CLK);

    if (this->_lastClk == nts::FALSE && clk == nts::TRUE) {
        this->_value++;
    }

    if (this->_value >= 4096) {
        this->_value = 0;
    }
}

nts::Tristate P4040Component::internalCompute(std::size_t pin) {
    nts::Tristate reset = this->computeInput(RS);

    if (reset == nts::TRUE) {
        this->_value = 0;
    }

    if (pin == Q1) {
        return (this->_value & 1) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q2) {
        return (this->_value & 2) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q3) {
        return (this->_value & 4) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q4) {
        return (this->_value & 8) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q5) {
        return (this->_value & 16) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q6) {
        return (this->_value & 32) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q7) {
        return (this->_value & 64) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q8) {
        return (this->_value & 128) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q9) {
        return (this->_value & 256) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q10) {
        return (this->_value & 512) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q11) {
        return (this->_value & 1024) ? nts::TRUE : nts::FALSE;
    } else if (pin == Q12) {
        return (this->_value & 2048) ? nts::TRUE : nts::FALSE;
    }
}