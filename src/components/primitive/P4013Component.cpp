/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "P4013Component.hpp"
using namespace nts::Components;

P4013Component::P4013Component(): AbstractComponent(14, "4013") {
    this->setPinMode(P4013Component::Q1, PinMode::OUTPUT);
    this->setPinMode(P4013Component::Q2, PinMode::OUTPUT);
    this->setPinMode(P4013Component::Q1B, PinMode::OUTPUT);
    this->setPinMode(P4013Component::Q2B, PinMode::OUTPUT);
}

void P4013Component::internalSimulate(std::size_t tick) {
    if (this->_lastSimulationTick == tick) {
        return;
    }

    // Simulate the flip-flops
    // First flip-flop
    Tristate clk1 = this->computeInput(P4013Component::CLK1);
    Tristate rs1 = this->computeInput(P4013Component::RS1);
    Tristate d1 = this->computeInput(P4013Component::D1);
    Tristate s1 = this->computeInput(P4013Component::S1);

    if (this->old_clk1 == nts::FALSE && clk1 == nts::TRUE) { // Rising edge
        if (rs1 == nts::TRUE) {
            this->ff1_q = nts::FALSE;
            this->ff1_qb = nts::TRUE;
        } else if (s1 == nts::TRUE) {
            this->ff1_q = nts::TRUE;
            this->ff1_qb = nts::FALSE;
        } else if (d1 == nts::TRUE) {
            this->ff1_q = nts::TRUE;
            this->ff1_qb = nts::FALSE;
        } else {
            this->ff1_q = nts::FALSE;
            this->ff1_qb = nts::TRUE;
        }
    }

    // Second flip-flop
    Tristate clk2 = this->computeInput(P4013Component::CLK2);
    Tristate rs2 = this->computeInput(P4013Component::RS2);
    Tristate d2 = this->computeInput(P4013Component::D2);
    Tristate s2 = this->computeInput(P4013Component::S2);

    if (this->old_clk2 == nts::FALSE && clk2 == nts::TRUE) { // Rising edge
        if (rs2 == nts::TRUE) {
            this->ff2_q = nts::FALSE;
            this->ff2_qb = nts::TRUE;
        } else if (s2 == nts::TRUE) {
            this->ff2_q = nts::TRUE;
            this->ff2_qb = nts::FALSE;
        } else if (d2 == nts::TRUE) {
            this->ff2_q = nts::TRUE;
            this->ff2_qb = nts::FALSE;
        } else {
            this->ff2_q = nts::FALSE;
            this->ff2_qb = nts::TRUE;
        }
    }

    this->old_clk1 = clk1;
    this->old_clk2 = clk2;
}

nts::Tristate P4013Component::internalCompute(std::size_t pin) {
    if (pin == P4013Component::Q1)
        return this->ff1_q;
    if (pin == P4013Component::Q1B)
        return this->ff1_qb;
    if (pin == P4013Component::Q2)
        return this->ff2_q;
    return this->ff2_qb;
}

std::unique_ptr<nts::IComponent> P4013Component::clone() const {
    return std::make_unique<P4013Component>();
}
